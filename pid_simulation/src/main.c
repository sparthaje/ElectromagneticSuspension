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

    p = pid_init((pid_ctrl_t*)malloc(sizeof(pid_ctrl_t)));
    pid_set_gains(p, gains[0], gains[1], gains[2]);

    FILE* fout;
    int j;
    double a, y_new;
    double* t = create_array(n);
    double* y = create_array(n);
    double* vy = create_array(n);
    t[0] = 0.0;
    y[0] = 0.0;
    vy[0] = 0.000000001;

    for(j = 1; j < n; j++){
        t[j] = t[j-1] + DT;
        a = (pid_step(p, error(y[j-1])))/M - g;
        vy[j] = vy[j-1] + DT*a;
        y[j] = y[j-1] + DT*vy[j];
        if(y[j] < 0 ){
            vy[j] = 0.0;
            y[j] = 0.0;
        }
        printf("A: %lf, VY: %lf, Y: %lf\n\n", a, vy[j], y[j]);
    }

    fout = fopen("../out.txt", "w");
    for(j = 0 ; j < n ; j+=200){
        fprintf(fout, "%d,%0.16f,%0.16f,%0.16f\n",j,  t[j], y[j], vy[j]);
    }


    return 0;
}