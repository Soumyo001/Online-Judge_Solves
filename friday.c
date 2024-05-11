#include<stdio.h>
int main(void)
{
    float cgpa[10];
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%f",&cgpa[i]);
    }
    for(i=0;i<10;i++)
    {
        cgpa[i]/=2;
                printf("id %d cgpa = %f\n",i,cgpa[i]);
    }

}
