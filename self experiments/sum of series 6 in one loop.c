#include<stdio.h>
int main(void){
    int total=0,sum=0,num,term=1;
    scanf("%d",&num);
    for(int i=1;i<=num;i+=2){
         if(term%2==0){
             sum+=i;
             total-=sum;
         }
         else{
             sum+=i;
             total+=sum;
         }
         term++;
    }
    printf("%d",total); 
}