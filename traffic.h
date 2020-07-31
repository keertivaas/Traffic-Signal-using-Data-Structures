#ifndef traffic_h
#define traffic_h

#include<stddef.h>
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

typedef struct
{
    char signame[50];
    int noofvehicles;
    int avg100insec;
    int time_taken;
}traffic;

#endif

