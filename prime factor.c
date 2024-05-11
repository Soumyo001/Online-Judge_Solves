#include<stdio.h>
int primefact(int x){
    static int i=2;
    if(i<x||x>1){
        if(x%i==0){
            printf("%d\t",i);
            return primefact(x/i);
        }
        else{
            i++;
            return primefact(x);
        }
    }
}
int main(void){
    int k;
    scanf("%d",&k);
    primefact(k);
}