#include<stdio.h>
void odd();
void even();
int n=1;
void odd(){
if(n<=20){
    if(n%2!=0){
    printf("%d is odd\n",n);
    n++;
    even();}
    else
        even();
}
}
void even(){
if(n<=20){
    if(n%2==0){
        printf("%d is even\n",n);
        n++;
        odd();}
    else
        odd();
}
}
int main(void){
even();
}
