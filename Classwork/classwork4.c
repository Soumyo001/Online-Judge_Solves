#include<stdio.h>
int d(int x) {
    if(x>0){
        return d(x/2)*10+x%2;
    }
}
int main(void){
    int n;
    scanf("%d",&n);
    printf("%d",d(n));
}