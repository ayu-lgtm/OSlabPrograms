#include <stdio.h>
#include <stdlib.h>
int i;
void arrangingavt(float a[i][6]);
void completionTime(float a[i][6]);
int main()
{
    printf("\nEnter the number of process:");
    scanf("%d",&i);
    float a[i][6];
    for(int k=1;k<=i;k++){
        for(int l=1;l<=6;l++){
            a[k][l]=0;}
    }
    float n,m;
    for(int k=1;k<=i;k++){
        printf("\n Arival time for process %d--",k);
        scanf("%f",&n);
        a[k][2]=n;
        printf("\n Burst  time for process %d--",k);
        scanf("%f",&m);
        a[k][3]=m;
        a[k][1]=k;
    }
    printf("P    |  A.T.  |  B.T.  |");
    printf("\n");
    printf("________________________");
    printf("\n");
    for(int k=1;k<=i;k++){
        for(int l=1;l<=3;l++){
            printf("%.2f  |  ",a[k][l]);
        }
        printf("\n");
    }
    arrangingavt(a);
    completionTime(a);
    return 0;
}
void arrangingavt(float a[i][6]){
    float swap;
    for(int k=1;k<i;k++){ 
        for(int l=k+1;l<=i;l++){
            if(a[k][2]>=a[l][2]){
                swap=a[k][1];
                a[k][1]=a[l][1];
                a[l][1]=swap;

                swap=a[k][2];
                a[k][2]=a[l][2];
                a[l][2]=swap;

                swap=a[k][3];
                a[k][3]=a[l][3];
                a[l][3]=swap;

            }
        }
    }
}
void completionTime(float a[i][6])
{
    int temp, val;
    a[1][4] = a[1][2] + a[1][3];
    a[1][6] = a[1][4] - a[1][2];
    a[1][5] = a[1][6] - a[1][3];

    for(int k=2; k<=i; k++)
    {
        temp = a[k-1][4];
        int low = a[k][3];
        for(int j=k; j<=i; j++)
        {
            if(temp >= a[j][2] && low >= a[j][3])
            {
                low = a[j][3];
                val = j;
            }
        }
        a[val][4] = temp + a[val][3];
        a[val][6] = a[val][4] - a[val][2];
        a[val][5] = a[val][6] - a[val][3];
        float temp;
        for(int m=1; m<=6; m++)
        {
            temp=a[val][m];
            a[val][m]= a[k][m];
            a[k][m]=temp;
        }
    }
    printf("\n\n");
    printf("\nGantt Chart:\n");
    printf("%.0f__",a[1][2]);
    for(int k=1;k<=i;k++)
    {
        printf("P[%.0f]__%.0f__",a[k][1],a[k][4]);
    }
    printf("\n\n\n");
    printf("P     |  A.T.  |  B.T.  |  W.T.  | T.A.T. |");
    printf("\n");
    printf("___________________________________________");
    printf("\n");
    for(int k=1;k<=i;k++){
        for(int l=1;l<=3;l++){
            printf("%.2f  |  ",a[k][l]);
        }
        for(int l=5;l<=6;l++){
            printf("%.2f  |  ",a[k][l]);
        }
        printf("\n");
    }
    printf("\n");
    float sum;
    sum=0;
    for(int n=1;n<=i;n++)
    {
        sum=sum+a[n][5];
    }

    printf("\n AVERAGE WAITING TIME: %.2f",(sum/i));
    printf("\n");
    float summ;
    summ=0;
    for(int n=1;n<=i;n++)
    {
        summ=summ+a[n][6];
    }

    printf("\n AVERAGE TURN ARROUND TIME: %.2f",(summ/i));
    printf("\n");
}
