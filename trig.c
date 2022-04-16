#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sched.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int a, b, c;


void main(){
    struct timeval timeNow;
    int d=10, x=10, y=10, a=8;
    printf("hello\n");

    printf("Enter distance D from wall: \n");
    //scanf("%d", d);

    printf("Enter x coordinates: \n");
    //scanf("%d", x);

    printf("Enter y coordinates: \n");
    //scanf("%d", y);

    printf("x y z: %d %d %d\n", x, y, d);

    gettimeofday(&timeNow, (void *)0);
    long start = timeNow.tv_usec;
    //a
    a = (4*d*d + 4*y*y);

    b = -2*d*(d*d + y*y);

    c = (d*d + y*y)*(d*d + y*y) - 4*(y*y*a*a);

    double ans1 = (-b + sqrt(b*b - 4*a*c))/2*a;     //x1

    double ans2 = (-b - sqrt(b*b - 4*a*c))/2*a;     //x1

    float angle1 = atan( (sqrt(a*a - ans1*ans1))/ans1 );

    float angle2 = atan( (sqrt(a*a - ans1*ans1))/ans1 );

    printf("Calculated angles: %f %f ", angle1, angle2);

    gettimeofday(&timeNow, (void *)0);

    printf("Time diff: %ld ", timeNow.tv_usec - start);


}