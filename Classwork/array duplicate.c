#include<stdio.h>
int main(void){
    int a[10],b[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<10;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i]==b[j]){
                printf("%d is duplicate at %d index of b\n",a[i],j+1);
            }
        }
    }
}