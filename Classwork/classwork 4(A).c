#include<stdio.h>
int main(void){
    int a[5],n,count=0;
    scanf("%d",&n);
     for(int i=0;i<5;i++)
         scanf("%d",&a[i]);
    for(int i=0;i<5;i++){
        if(n==a[i]){
            count++;
        }
    }
    if(count)printf("Present\n");
    else printf("Absent");
}