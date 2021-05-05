#include <stdio.h>
#include <stdlib.h>
void gchart(float a[],float b[],int c[],int i)
{
    c[0]=a[0];
    for(int l=0;l<i+1;l++)
    {
        c[l+1]=c[l]+b[l];
    }
    for(int l=0;l<i+1-1;l++)
    {
        printf("[%d]-p%d-",c[l],l);
    }
    printf("[%d]",c[i+1-1]);
    printf("\n");
}
void wtime(float a[],int c[],float d[],int i)
{
    for(int n=0;n<i;n++)
    {
        d[n]=c[n]-a[n];
    }
    for(int n=0;n<i;n++)
    {
        printf("\n waiting time for process %d--%.2f",n,d[n]);
    }

    printf("\n");
    float sum=0;
    for(int n=0;n<i;n++)
    {
        sum=sum+d[n];
    }

    printf("\n AVERAGE WAITING TIME: %.2f",(sum/i));
    printf("\n");
}
void taround(float d[],float b[],float e[],int i)
{
    for(int n=0;n<i;n++)
    {
        e[n]=d[n]+b[n];
    }
    for(int n=0;n<i;n++)
    {
        printf("\n Turn around time for process %d--%.2f",n,e[n]);
    }
    printf("\n");
    float sum=0;
    for(int n=0;n<i;n++)
    {
        sum=sum+e[n];
    }

    printf("\n AVERAGE TURN_AROUND TIME: %.2f",(sum/i));
}
int main()
{
    int i;

    printf("\nEnter the number of process:");
    printf("\nAssume that all process arival time given in increasing order...\n");
    scanf("%d",&i);
    float a[i],b[i],d[i],e[i];
    int c[i+1];
    for(int k=0;k<i;k++)
    {
        printf("\n Arival time for process %d--",k);
        scanf("%f",&a[k]);
        printf("\n Burst time for process %d--",k);
        scanf("%f",&b[k]);
    }
    printf("\n Gantt Chart : ");

    gchart(a,b,c,i);

    wtime(a,c,d,i);

    taround(d,b,e,i);
    return 0;
}
