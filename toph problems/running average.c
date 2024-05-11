#include<stdio.h>
int main(void)
{
    int count=0,i,t;
    scanf("%d",&t);
    int n[t];
    double temp[t];
    for(i=0;i<t;i++)
    {
        scanf("%d",&n[i]);
    }
    for(i=0;i<t;i++)
    {
        temp[i]=0;
    }
    for(i=0;i<t;i++)
    {
        for(int j=0;j<=i;j++)
        {
            temp[i]+=n[j];
        }
        count++;
        temp[i]/=count;
    }
    for(i=0;i<t;i++)
    {
        int data=(int)temp[i];
        if(data==temp[i])
            printf("%.0lf\n",temp[i]);
        else
            printf("%.10lf\n",temp[i]);
    }
}
