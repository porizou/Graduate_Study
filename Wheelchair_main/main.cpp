/*------------------------
cp /Users/mori/LPCXpresso/workspace/Wheelchair_main/Debug/Wheelchair_main.bin /Volumes/MBED/ && diskutil unmount /Volumes/MBED/
screen /dev/tty.usbmodem1412 9600
------------------------*/

#include "main.h"

DigitalOut led1(LED1,0);
DigitalOut led2(LED2,0);
DigitalOut led3(LED3,0);
DigitalOut led4(LED4,0);

DigitalIn SW[2] = { DigitalIn(p25), DigitalIn(p26)};

BusIn Rotary(p22, p24, p21, p23); //ロータリースイッチ入力

ACM1602NI lcd(p28, p27);
Serial pc(USBTX, USBRX);

float motorR = 0.0, motorL = 0.0;
float Speed  = 0.3;

float Angle = 0;
float sideDistance = 0;

bool isControllDistance = 0;
bool  isControllHeading = 0;

bool isMoving = 0;

uint16_t MovingDistance = 0;

Mutex spi_mutex;

//モード選択関数ポインタの宣言
void (*MODE_SELECT[])(void) = {
	Mode,
	Mode1,
	Mode2,
	Mode3,
	PID_Tuning_Mode,
	Heading_Mode,
	 Left_Distance_Mode,
	Right_Distance_Mode,
	Front_Distance_Mode,
	Compass_Calibrate_Mode,
	Mode,
	Mode,
	Mode,
	Mode,
	mesureMode2,
	mesureMode1
};

int main() {

	//各RTOSタイマーの宣言
	RtosTimer DistanceControll(DistanceThread); //距離制御
	RtosTimer HeadingControll(HeadingThread);   //方向制御

	//モータ制御用マイコンとの通信用スレッド
	//Thread can_thread(CAN_Thread, NULL, osPriorityNormal);
	Thread spi_thread(SPI_Thread, NULL, osPriorityNormal);  //CAN通信が安定しないため,SPI通信に変更

	Thread sd_thread(SD_Thread, NULL, osPriorityNormal, (DEFAULT_STACK_SIZE * 2.5));

// Priority of Thread (RtosTimer is osPriorityAboveNormal)
//  osPriorityIdle          = -3,          ///< priority: idle (lowest)--> then, mbed ERROR!!
//  osPriorityLow           = -2,          ///< priority: low
//  osPriorityBelowNormal   = -1,          ///< priority: below normal
//  osPriorityNormal        =  0,          ///< priority: normal (default)
//  osPriorityAboveNormal   = +1,          ///< priority: above normal
//  osPriorityHigh          = +2,          ///< priority: high 
//  osPriorityRealtime      = +3,          ///< priority: realtime (highest)
//  osPriorityError         =  0x84        ///< system cannot determine priority or thread has illegal priority

	int mode  = 0;
	int pmode = 0;

	//RTOSタイマーのスタート
	DistanceControll.start(DistanceControllCycle * 1000);
	HeadingControll.start(HeadingControllCycle * 1000);

    while(1) {

    	mode = Rotary;

    	//モードが切り替わったらPID制御を無効にする
    	if(mode != pmode) {
    		controll_reset(); wait(1);
    		for(int i = 0; i < 10; i++) {
    			lcd.cls();
    		}
    	}
    	pmode = mode;

    	(*MODE_SELECT[mode])();

    }
}

bool SW_ON(int n) {

	if(!SW[n - 1]) {
		wait(0.1);
		if(SW[n -1]) {
			wait(0.1);
			return 1;
		}
	}
	return 0;
}

bool isDetectFrontObject(float distance) {
	return (FRONT_AREA-5 <= distance || distance <= FRONT_AREA) ? 1 : 0;
}

inline void controll_reset(void) {
	isControllDistance = 0;
	isControllHeading  = 0;
	
	motorL = 0.0; motorR = 0.0;
}


