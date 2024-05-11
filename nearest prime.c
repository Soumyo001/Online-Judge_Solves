#include<stdio.h>
int nprime(int n){
    int count=0;
    for(int i=2;i<n;i++)
    {
        if(n%i==0){
            count++;
            break;
    }
    }
    if(count)
        return 0;
    else
        return 1;

}
int main(void){
    int n,d1=0,d2=0,n1=0,n2=0;
    scanf("%d",&n);
    for(int i=n;;i++){
        if(nprime(i)){
            d1=i-n;
            n1=i;
            break;
        }
    }
    for(int i=n;;i--){
        if(nprime(i)){
        d2=n-i;
        n2=i;
        break;}
    }
    if(d1==d2)
       printf("%d is prime",n1);
    else if(d1<=d2){
        printf("Nearest prime number %d is %d",n,n1);
    }
    else if(d2<d1){
        printf("Nearest prime number %d=%d and %d",n,n2,n1);
    }
}