/*
  PID.cpp - PID Library
*/

#include "Arduino.h"
#include "PID.h"

PID::PID(
            float y0, float setPoint, float maxForce, float minForce,
            float kp, float ki, float kd, float n, 
            float samplingPeriod
        ) {
    
    initialPosition = y0;
    
    maximumForce = maxForce;
    minimumForce = minForce;

    previousError = setPoint - y0;
    integral = 0;
    elapsedTime = 0;

    proportionalGain = kp;
    integralGain = ki;
    derivativeGain = kd;
    filterCoefficient = n;

    sampleTime = samplingPeriod;
}

float PID::saturate(float force) {
    if (force > maximumForce) {
        return maximumForce;
    }
    if (force < minimumForce) {
        return minimumForce;
    }
    return force;
}

float PID::step(float error, float currentTime) {
    // Proportional
    float p = error * proportionalGain;

    // Integral
    integral += 0.5 * (error + previousError) * (currentTime - elapsedTime);
    float i = integral * integralGain;

    // Derivative
    float derivative = (error - previousError) / (currentTime - elapsedTime);
    float d = derivative * derivativeGain;

    previousError = error;
    elapsedTime = currentTime;

    return saturate(p + i + d);
}

bool PID::ready(float currentTime) {
    return currentTime - elapsedTime > sampleTime;
}