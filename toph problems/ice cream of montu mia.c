#include<stdio.h>
int main(void){
    int n,a,b,c,count=0;
    scanf("%d",&n);scanf("%d%d%d",&a,&b,&c);
    if(n-a>=10)
        count=1;
    else if(n-b>=10)
        count=1;
    else if(n-c>=10)
         count=1;
    if(count)
       printf("Yes :-D");
    else
    printf("No :-(");
}