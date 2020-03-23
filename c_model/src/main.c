#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <pid.h>

#define g 9.81 // m/s^2
#define M 5 // kg
#define Y 0.01// m
#define DT 0.25 // s
#define n (int)(0.5 + (4*60*60) /DT) // 90 minutes

static inline double* create_array(int length){ return malloc(sizeof(double) * length); }
static inline double error(double y){ return Y-y; }

pid_ctrl_t* p;


double* parse_args( char** argv){
    static double gains[3];
    sscanf(argv[1], "%lf", &gains[0]);
    sscanf(argv[2], "%lf", &gains[1]);
    sscanf(argv[3], "%lf", &gains[2]);

    return gains;
}


int main(int argc, char** argv){
    if(argc != 4){ 
        fprintf(stderr, "Missing parameters!\n"); 
        return -1;
    }

    double* gains = parse_args(argv);

    p = pid_init((pid_ctrl_t*)malloc(sizeof(pid_ctrl_t))); // initialize PID controller
    pid_set_gains(p, gains[0], gains[1], gains[2]); // set gains to CLI args
    pid_set_time_step(p, DT); // set PID time step

    FILE* fout; // output file
    int j; 
    double a;
    double* t = create_array(n); // create arrays
    double* y = create_array(n);
    double* vy = create_array(n);
    t[0] = 0.0; // initial values
    y[0] = 0.0;
    vy[0] = 0.000000001;

    for(j = 1; j < n; j++){
        t[j] = t[j-1] + DT; // update time
        a = (pid_step(p, error(y[j-1])))/M - g; // calculate net acceleration
        vy[j] = vy[j-1] + DT*a; // Update velocity 
        y[j] = y[j-1] + DT*vy[j]; // Update position
        if(y[j] < 0){ // Pod cannot go below track => position cannot be negative
            y[j] = 0.0; // Reset position to 0
            vy[j] = 0.0; // Reset veloicty to 0
        }
        printf("A: %lf, VY: %lf, Y: %lf\n\n", a, vy[j], y[j]); // debugging
    }

    fout = fopen("../out.txt", "w");
    for(j = 0 ; j < n ; j+=200){ // Output to file, increment by 200 b/c too many points over saturates graph
        fprintf(fout, "%d,%0.16f,%0.16f,%0.16f\n",j,  t[j], y[j], vy[j]);
    }


    return 0;
}