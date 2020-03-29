#ifndef PID_h
#define PID_h

#include "Arduino.h"

class PID {

  public:
    PID(
        float y0, 
        float setPoint, 
        float maxForce,
        float minForce,

        float kp, 
        float ki,
        float kd, 
        float n, 

        float samplingPeriod
        );
    
    float step(float error, float currentTime);
    bool ready(float currentTime);

  private:
    float saturate(float force);
    
    float initialPosition;
    float maximumForce;
    float minimumForce;
    
    float previousError;
    float integral;
    float elapsedTime;

    float proportionalGain;
    float integralGain;
    float derivativeGain;
    float filterCoefficient;

    float sampleTime;

};

#endif
