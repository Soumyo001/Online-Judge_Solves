#include<stdio.h>
void input(int size,int a[size]){
    for(int i=0;i<size;i++)
       scanf("%d",&a[i]);
}
void display(int x,int a[x]){
    for(int i=0;i<x;i++)
        printf("%d ",a[i]);
}
int main(void){
    int size;
    scanf("%d",&size);
    int a[size];
    input(size,a);
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]-a[j]>0){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
            /*if(a[i]-a[j]<0){
                int t=a[j];
                a[j]=a[i];
                a[i]=t;
            }*/
            }
        }
    display(size,a);
    }