/*
 *  process.c
 *
 *  Created on:     19-April-2022
 *  Author:         Kamini Budke
 *  Description:    translates pixel cooridnates to servo angles;                   (completed)
 *                  accepts from camera task;                                       (-)
 *                  writes to two buffers which act as inputs for the servo motor   (-)
 *  TODO:           compute for relativity with regards to pixel coordinates (x = x_incoming/(PIXEL_MAX)*(ARM_MAX))
 *                  incorporate offset angle of servo motor    
 */


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

#define PI 3.14
#define ARM_LEN 20     //20 cm

int d_wall = 40;        // 40 cm
int x = 0, y = 0;
float angle1, angle2;

void main(){
    struct timeval timeNow;
    printf("hello\n");

    printf("Distance D from wall: %d\n", d_wall);

    printf("Enter x coordinates: \n");
    scanf("%d", &x);

    printf("Enter y coordinates: \n");
    scanf("%d", &y);

    if(y > ARM_LEN - 1){
        printf("Exceeds range of arm\n");;
        exit(-1);                           //yield task in RTOS instead of exit
    }

    gettimeofday(&timeNow, (void *)0);
    long start = timeNow.tv_usec;
    
    angle1 = (atan((float)x/d_wall))*(180)/PI; 

    angle2 = (asin((float)(-y)/ARM_LEN))*(180)/PI; 
    
    printf("Calculated angles: %f %f \n", angle1, angle2);

    gettimeofday(&timeNow, (void *)0);

    printf("Time diff: %ld \n", timeNow.tv_usec - start);


}