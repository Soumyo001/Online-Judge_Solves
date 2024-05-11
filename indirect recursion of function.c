#include<stdio.h>
void even();
void odd();
int n=1;
void even()
{
    if(n<=10){
    printf("%d\t",n-1);
    n++;
    odd();
    return;
    }
}
void odd()
{
    if(n<=10){
    printf("%d\t",n+1);
    n++;
    even();
    return;
}
}
void main()
{
    odd();
}

