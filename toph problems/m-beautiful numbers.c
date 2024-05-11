#include<stdio.h>
int main(void){
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r,m,count=0,sum=0;scanf("%d%d%d",&l,&r,&m);
        for(int i=l;i<r;i++){
               if(i%m==0){
                   for(int j=i;j>0;j/=10){
                        sum+=(j%10);
                   }
                   if(sum%m==0) count++;
               }
        }
        printf("%d\n",count);
    }
}