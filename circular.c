#include "circular.h"

eletype dequeue(pq* a)
{
    eletype x = a->data[a->front];
    a->front = (a->front + 1)%a->maxsize;
    if(a->front==0)
        a->front++;
    return x;

}
