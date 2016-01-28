  /**
 * Includes
 */
 #include "PIDcontroller.h"

 PID::PID(float Kp, float Ki, float Kd, float tSample){

    tSample_ = tSample;

    Kp_ = Kp; Ki_ = Ki; Kd_ = Kd;
    
    setPoint_             = 0.0;
    processVariable_      = 0.0;
    controllerOutput_     = 0.0;
    prevControllerOutput_ = 0.0;

    accError_ = 0.0;
    Error_    = 0.0;
    prevError_= 0.0;
    Bias_     = 0.0;

    usingFeedForward = 0;
    usingIncompleteDifferential = 0;

    prevDiffError = 0.0;
 }

 void PID::setInputLimits(float inMin, float inMax){

    if(inMin >= inMax) return;
     
    inMin_  = inMin;
    inMax_  = inMax;
    inSpan_ = inMax - inMin;
 }

 void PID::setOutputLimits(float outMin, float outMax){

    if(outMin >= outMax) return;

    outMin_  = outMin;
    outMax_  = outMax;
    outSpan_ = outMax - outMin;
 }

 void PID::setBias(float Bias) {
    Bias_ = Bias;
    usingFeedForward = 1;
 }

 void PID::setIncompleteDifferential(float lpf) {
    LPF = lpf;
    usingIncompleteDifferential = 1;
 }

 void PID::setSetPoint(float sp){
    setPoint_ = sp;
 }

 void PID::setProcessValue(float pv){
    processVariable_ = pv;
 }

void PID::setGain(float Kp, float Ki, float Kd) {
    Kp_ = Kp; Ki_ = Ki; Kd_ = Kd;
}

 float PID::compute(){

    //現在値と目標値の値を0~100%の範囲に置き換える
    float scaledPV = (processVariable_ - inMin_) / inSpan_;

    if(scaledPV > 1.0){
        scaledPV = 1.0;
    } else if(scaledPV < 0.0){
        scaledPV = 0.0;
    }

    float scaledSP = (setPoint_ - inMin_) / inSpan_;

    if (scaledSP > 1.0){
        scaledSP = 1.0;
    } else if(scaledSP < 0.0){
        scaledSP = 0.0;
    }

    //偏差の計算
    Error_= scaledSP - scaledPV;

    //アンチワインドアップ
    if (!(prevControllerOutput_ >= 1 && Error_ > 0) && !(prevControllerOutput_ <= 0 && Error_ < 0)) {
        accError_ += (Error_ + prevError_) / 2.0 * tSample_; //偏差の積分値の計算
    }

    //偏差の微分値の計算
    float diffError = (Error_ - prevError_) / tSample_;
    
    //不完全微分が有効な場合,偏差の微分値をLPFに通す
    if(usingIncompleteDifferential) { 
        diffError = (LPF * prevDiffError) + (diffError * (1.0 - LPF));
        prevDiffError = diffError;
    }

    //フィードフォワード制御が有効な場合,バイアス値の計算
    float scaledBias = usingFeedForward ? (Bias_ - outMin_) / outSpan_ : 0.0;

    //PIDの計算
    controllerOutput_ = scaledBias + Kp_ * Error_ + Ki_ * accError_ + Kd_ * diffError; 

    if (controllerOutput_ < 0.0) {
        controllerOutput_ = 0.0;
    } else if (controllerOutput_ > 1.0) {
        controllerOutput_ = 1.0;
    }
    //出力の値,偏差の値を更新
    prevControllerOutput_ = controllerOutput_;
    prevError_ = Error_;
    //PIDの出力を実際の値に変換して返す
    return ((controllerOutput_ * outSpan_) + outMin_);

 }
























