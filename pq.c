#include"traffic.h"
#include "pq.h"
#include"circular.h"


pq* create(int maxsize)
{
    pq *a;
    traffic temp;
    temp.avg100insec=-100;
    temp.noofvehicles=-50;
    temp.time_taken=-100;
    strcpy(temp.signame," ");
    a=(pq*)malloc(sizeof(pq));
    a->front = 1;
    a->maxsize=maxsize+1;
    a->rear = 1;
    a->data=(eletype*)malloc((a->maxsize)*sizeof(eletype));
    a->size=0;
    a->data[0]=temp;
    return a;
}

int print(eletype t)
{
    printf("\n\n%s : ",t.signame);
    printf("\n Green : %dsec",t.time_taken);
    return 0;
}


int insert(pq *arr, eletype data)
{

    	if(arr->size==0)
    	{
        arr->data[1]=data;
        (arr->size)++;
        return 1;
         }
        (arr->size)++;
        (arr->rear)++;
    if(arr->size>1)
    {
        arr->data[arr->size]=data;
        int i = arr->size;
        while((i/2)>0)
        		{
                if((arr->data[i].time_taken)>(arr->data[i/2].time_taken)) //max impl
            {

                eletype temp = arr->data[i];
                arr->data[i] = arr->data[i/2];
                arr->data[i/2] = temp;
                i=i/2;
            }
            else i--;

     }
        return 1;
    }
}


int display(pq* a)
{
     char sname[10][10];
    int i;char choice = 'N';
    pq*temp=a;
    pq*tem=a;
    while(1)
    {
        for(i=1;i<=a->size;i++)
            print(a->data[i]);
        printf("\nDo u want to continue ? Y or N : ");
        scanf("\n%c",&choice);
        if(choice=='N'|| choice== 'n')
            break;
        eletype y[a->size];
        int g=a->size;
        for(i=a->front;i<=a->rear;i++)
        {
            eletype x = dequeue(temp);
            strcpy(sname[i],x.signame);
        }
        free(a);
        a=create(g);
        for(i=1;i<=g;i++)
        {
            y[i]=scan(sname[i]);
            insert(a,y[i]);
        }

    }
    return 0;
}


