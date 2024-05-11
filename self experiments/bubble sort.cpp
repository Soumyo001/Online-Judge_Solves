#include<bits/stdc++.h>
using namespace std;
void input(int *arr,int l){
    for(int i=0;i<l;i++){
       scanf("%d",(arr+i));
    }
}
void output(int *arr,int l){
    for(int i=0;i<l;i++){
        printf("%d ",*(arr+i));
    }
}
int main(void) {
     int a[10];
     input(a,10);
     for(int i=0;i<9;i++){
         for(int j=i+1;j<10;j++){
             if(a[i]>a[j]){
                 int t=a[i];
                 a[i]=a[j];
                 a[j]=t;
             }
         }
     }
     output(a,10);
}