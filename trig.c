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
    int d=8, x=1, y=6, a1=10;
    printf("hello\n");

    printf("Enter distance D from wall: \n");
    //scanf("%d", d);

    printf("Enter x coordinates: \n");
    //scanf("%d", x);

    printf("Enter y coordinates: \n");
    //scanf("%d", y);

    printf("a y d: %d %d %d\n", a, y, d);

    gettimeofday(&timeNow, (void *)0);
    long start = timeNow.tv_usec;
    //a
    a = (4*d*d + 4*y*y);
    printf("Calculated a: %d \n", a);

    b = -2*d*(d*d + y*y);   
    printf("Calculated b: %d \n", b);

    c = (((d*d) + (y*y))*((d*d) + (y*y))) - (4*(y*y)*(a1*a1));
    printf("Calculated c: %d \n", c);

    float check = b*b - 4*a*c;
    printf("Calculated check: %f \n", check);

    float ans1 = (-b + sqrt(b*b - 4*a*c))/2*a;     //x1

    float ans2 = (-b - sqrt(b*b - 4*a*c))/2*a;     //x1

    printf("Calculated x1s: %f %f \n", ans1, ans2);

    float angle1 = atan( (sqrt(a1*a1 - ans1*ans1))/ans1 );

    float angle2 = atan( (sqrt(a1*a1 - ans1*ans1))/ans1 );

    printf("Calculated angles: %f %f \n", angle1, angle2);

    gettimeofday(&timeNow, (void *)0);

    printf("Time diff: %ld \n", timeNow.tv_usec - start);


}