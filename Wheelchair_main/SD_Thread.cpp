#include "mbed.h"
#include "main.h"

SDFileSystem sd(p5, p6, p7, p8, "sd");
Timer timer;

#if 0

void SD_Thread(void const *sdcard) {

	FILE *fp;
	if(NULL == (fp = fopen("/sd/Ultrasonic/imu.txt", "w"))) led2 = 1;
	double t = 0.0;

	while(!isMoving);

	while(isMoving) {
		timer.start();
		fprintf(fp, "%0.3lf,%0.3f,%0.3f,%0.3f,%0.3f,%0.3f\n", t, Angle,
			motorR, motorL, controll_distance.processVariable_, controll_distance.prevDiffError );
		Thread::wait(100);
		timer.stop();

		t += timer.read();
		timer.reset();
	}
	fclose(fp);
	led2 = 1;
}

#endif

//移動距離-地磁気測定データ
#if 0

void SD_Thread(void const *sdcard) {

	FILE *fp;
	if(NULL == (fp = fopen("/sd/GraduateStudy/compass-movingdistance.txt", "w"))) led2 = 1;
	double t = 0.0;

	while(1) {
		//led4 = !led4;
		timer.start();
		fprintf(fp, "%0.5f,%0.5f,%0.5f,%0.5f,%0.5f,%d\n", t, Angle, imu.m_x, imu.m_y, imu.heading, MovingDistance );
		Thread::wait(100);
		timer.stop();

		t += timer.read();
		timer.reset();

		if(t > 30) break;
	}
	fclose(fp);
	led2 = 1;
}

#endif

//方向制御測定データ
#if 0

void SD_Thread(void const *sdcard) {

	FILE *fp;
	if(NULL == (fp = fopen("/sd/GraduateStudy/HeadingControll.txt", "w"))) led2 = 1;
	double t = 0.0;

	while(!isMoving);

	while(isMoving) {
		led4 = !led4;
		timer.start();

		float Dist = sideDistance;
		fprintf(fp, "%0.3lf, %0.3f, %0.3f, %0.3f, %0.3f, %0.3f,%d\n", t, Angle,
			imu.heading, motorR, motorL, Dist, MovingDistance);
		Thread::wait(10);
		timer.stop();

		t += timer.read();
		timer.reset();
	}
	fclose(fp);
	led2 = 1;
}

#endif

//距離制御測定データ
#if 1

void SD_Thread(void const *sdcard) {

	FILE *fp;
	if(NULL == (fp = fopen("/sd/GraduateStudy/DistanceControll.txt", "w"))) led2 = 1;
	double t = 0.0;

	while(!isMoving);

	while(isMoving) {
		timer.start();

		float Dist = sideDistance;
		fprintf(fp, "%0.3lf, %0.3f, %0.3f, %0.3f, %0.3f, %0.3f, %d\n",
				t, Angle, imu.heading, motorR, motorL, Dist, MovingDistance);
		Thread::wait(100);
		timer.stop();

		t += timer.read();
		timer.reset();
	}
	fclose(fp);
	led2 = 1;
}

#endif
