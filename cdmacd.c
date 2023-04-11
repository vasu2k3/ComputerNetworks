#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<sys/time.h>
int x=0;
void capture()
{
        exit(0);
}
int get()
{
        return x;
}
void put()
{
        x++;
}
void node(char *p)
{
        int name;
        int frame1,frame2,i=0;
        long int t;
        struct timeval tv;
        struct timezone tz;
        name=atoi(p);
        while(1)
        {
                frame1=get();
                frame2=get();
                if(frame1==frame2)
                {
                        put();
                        frame1=get();
                        printf("station %d transmitting frame %d\n",name,++i);
                        _sleep(3);
                        frame2=get();
                        if(frame1!=frame2)
                        {
                                printf("station %d collision occured %d \n",name,i--);
                                sleep(3);
                        }
                        else
                        {
                                printf("station %d complete\n",name,i);
                        }
                }
                sleep(3);
        }
}
int main()
{
        pthread_t t1,t2,t3;
        pthread_create(&t1,0,(void *)node,"1");
        pthread_create(&t2,0,(void *)node,"2");
        pthread_create(&t3,0,(void *)node,"3");
        while(1);
}
