#include "pq.h"
#include"traffic.h"

eletype scan(char a[10])
{
      srand(time(0));
      traffic t;
      while ((getchar()) != '\n'); // Flushes the buffer
      strcpy(t.signame,a);
      t.noofvehicles = (rand()%50)+1;
      srand(time(0));
      t.avg100insec = (rand()%120)+1;
      t.time_taken = ((t.noofvehicles*t.avg100insec)/100);
      return t;
}

//int print(eletype t)
//{
//    printf("\n\n%s : ",t.signame);
//    printf("\n Green : %dsec",t.time_taken);
//    return 0;
//}

int main()
{
    pq *a;
    printf("\n-------TRAFFIC SIGNAL SIMULATION-------\n\n");
    int num,i;
    char sname[100];
    char choice = 'N';
    printf("Enter number of Signals : ");
    scanf("%d",&num);
    num*=2; //Each signal has straight and right

        traffic t[num+1];
        a = create(100);
        for(i=0;i<num;i++)
        {
            printf("\nSignal Description : ");
            //while ((getchar()) != '\n');
            fflush(stdin);
            scanf("%s",sname);
            t[i+1] = scan(sname);
            insert(a,t[i+1]);
        }
        printf("\nPriority of Signals according to no of vehicles :\n");
        display(a);
        free(a);

    printf("\n-------THANK YOU FOR USING THIS MODULE-------\n\n");
    return 0;
}

