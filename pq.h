#ifndef pq_h
#define pq_h
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
#include"traffic.h"
#include<time.h>

typedef traffic eletype;

typedef struct
{
    int size;
    int maxsize;
    int front,rear;
    eletype *data;
}pq;

pq* create(int);
int insert(pq*,eletype);
int display(pq*);
int delete_min(pq*);
eletype scan(char[]);
#endif

