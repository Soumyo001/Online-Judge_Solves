#include<stdio.h>
long long int npr(int x){
   if(x==1)
   return 1;
   else
    return x*npr(x-1);
}
int main(void){
    int n,r;
    scanf("%d%d",&n,&r);
    printf("%lld",npr(n)/(npr(n-r)*npr(r)));
}