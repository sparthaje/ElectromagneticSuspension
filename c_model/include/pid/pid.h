#pragma once

typedef struct
{
    double kp, ki, kd;
    double integrator;
    double previous_err;
    double time_step;
} pid_ctrl_t;

pid_ctrl_t* pid_init(pid_ctrl_t* pid);
void pid_reset_gains(pid_ctrl_t* pid);
void pid_set_time_step(pid_ctrl_t* pid, double t);
void pid_reset_integration(pid_ctrl_t* pid);
void pid_set_gains(pid_ctrl_t* pid, double p, double i, double d);

double pid_step(pid_ctrl_t* pid, double error);
double pid_get_previous_error(pid_ctrl_t* pid);
double pid_get_current_integration(pid_ctrl_t* pid);
