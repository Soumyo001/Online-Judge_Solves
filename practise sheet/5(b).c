#include<stdio.h>
void pattern(int n){
    for(int i=3;i<=n;i+=2){
        for(int j=1;j<=n;j++){
            printf("%d*%d=%d\t",i,j,i*j);
        }
        printf("\n");
    }
}
int main(void){
    int n;
    scanf("%d",&n);
    pattern(n);
}