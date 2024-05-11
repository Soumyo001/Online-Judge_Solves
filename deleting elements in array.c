#include<stdio.h>
void input(int x,int a[]){
    for(int i=0;i<x;i++) scanf("%d",&a[i]);
}
void display(int x,int a[]){
    for(int i=0;i<x;i++) printf("%d\t",a[i]);
}
int main(void){
    int a[100],n,count=0;
    scanf("%d",&n);
    input(n,a);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(int k=j;k<n-1;k++)
                    a[k]=a[k+1];
                n--;
            }
        }
    }
    display(n,a);
}