#include<stdio.h>
int main(void){
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++){
    int n,k=0;
    scanf("%d",&n);
    for(int i=n;i!=0;i/=10){
        if((i%10)!=0) k++;
    }
    if(k==1) printf("The amount is %d taka\n",n);
    else if(k==3){
        int l;
        l=n%100;n=n/100;
        printf("The amount is %d hundred %d taka\n",n,l);
    }
    else if(k==4){
        int o,m;
        o=n%100;n=n/100;m=n%10;n=n/10;
        printf("The amount is %d thousand %d hundred %d taka\n",n,m,o);
    }}
}