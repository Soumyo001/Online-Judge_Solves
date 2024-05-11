#include<stdio.h>
int main(void){
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++){
    if((i%3==0||i%7==0)&&(i%7!=0||i%3!=0)) printf("%d\t",i);
 }
}
