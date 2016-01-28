#include "read_velocity.h"

ReadVelocity::ReadVelocity(PinName A , PinName B ,  int pulseNum ,  float Sample ) : 
							 qei(A , B , NC , pulseNum , QEI::X4_ENCODING) {

	pulseNum_ = pulseNum;
	Sample_   = Sample;

	initParam();

	/* 速度制御タイマー割り込み開始 */
	sampleTicker.attach(this , &ReadVelocity::readEncoder , Sample_);
}

void ReadVelocity::initParam(void) {

	qei.reset();
	/* 現在の回転角を原点に設定 */
	Angle = pAngle = (float)qei.getPulses()/(float)pulseNum_*2.0*PI;

	Velocity  = 0.0;
	pVelocity = 0.0;
}

void ReadVelocity::readEncoder(void) {

	pAngle = Angle ; // 前回の回転角を更新

	/* エンコーダから回転角を取得 */
	Angle = (float)qei.getPulses()/(float)pulseNum_*2.0*PI;
}

float ReadVelocity::culcVelocity(void) {

	float dAngle ;

	dAngle = Angle - pAngle ; // 角度の差分を計算

	while(dAngle > PI){ dAngle -= 2*PI;} //角度の差分の範囲を-π~πにする
	while(dAngle <-PI){ dAngle += 2*PI;}

	/* 速度を計算(回転角の微分 dAngle/Sample_)して、一次LPFに通す
	   現在の速度 = LPF係数 × 前回の速度 + 現在の速度 × (1 - LPF係数) */
	Velocity = LPF * pVelocity + (dAngle/Sample_) * (1.0-LPF);
	pVelocity = Velocity; //前回の速度を更新

	return Velocity;
}

int ReadVelocity::getPulse(void) {
	return qei.getPulses();
}

float ReadVelocity::getAngle(void) {

	return Angle;
}

float ReadVelocity::getRevolution(void) {

	return qei.getPulses() / pulseNum_;
}
