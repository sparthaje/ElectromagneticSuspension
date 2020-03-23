#include <pid.h>

pid_ctrl_t* pid_init(pid_ctrl_t* pid){
    pid_set_gains(pid, 0.0, 0.0, 0.0);
    pid->integrator = 0.0;
    pid->previous_err = 0.0;
    return pid;
}

void pid_set_gains(pid_ctrl_t* pid, double p, double i, double d){
    pid->kp = p;
    pid->ki = i;
    pid->kd = d;
}

void pid_reset_gains(pid_ctrl_t* pid){
    pid->kp = 0.0;
    pid->ki = 0.0;
    pid->kd = 0.0;
}

void pid_reset_integration(pid_ctrl_t* pid){
    pid->integrator = 0.0;
}

double pid_step(pid_ctrl_t* pid, double error){
    double output;
    pid->integrator += error;
    pid->previous_err = error;
    
    output = pid->kp * error;
   // output += pid->ki * pid->integrator;
    
    printf("F: %lf\n", output);
    return output;
}

double pid_get_previous_error(pid_ctrl_t* pid){
    return pid->previous_err;
}

double pid_get_current_integration(pid_ctrl_t* pid){
    return pid->integrator;
}
