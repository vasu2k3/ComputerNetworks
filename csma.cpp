#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int i,j,k,n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    srand(time(NULL));
    int a[n],b[n];
    for(i=0;i<n;i++)
    {
        a[i]=rand()%10;
        b[i]=rand()%10;
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("Node %d:\n",i+1);
        printf("Data:%d\n",a[i]);
        printf("Time:%d\n",b[i]);
        printf("\n");
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(b[i]==b[j])
                {
                    if(a[i]>a[j])
                    {
                        printf("Collision detected between node %d and node %d\n",i+1,j+1);
                        printf("Node %d wins\n",i+1);
                        printf("\n");
                    }
                    else
                    {
                        printf("Collision detected between node %d and node %d\n",i+1,j+1);
                        printf("Node %d wins\n",j+1);
                        printf("\n");
                    }
                }
            }
        }
    }
    getch();
}