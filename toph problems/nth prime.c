#include<stdio.h>
#include<stdlib.h>
long long int isprime(int x){
      long long int i=0,c=2,co=0;
      int *p;
      p=(int *)malloc(sizeof(int)*x);
        while(c){
           for(int k=2;k<c;k++){
                if(c%k==0){
                    co++;
                   break;}
            }
            if(co==0){
               p[i]=c;
               i++;}
            co=0;
            c++;
            if(i==x){
                return p[i-1];
                break;
            }
        }
}
int main(void){
    long long int n;
    scanf("%lld",&n);
    printf("%lld",isprime(n));
}
