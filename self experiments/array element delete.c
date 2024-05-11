#include<stdio.h>
void input(int s,int a[]){
  for(int i=0;i<s;i++) scanf("%d",&a[i]);
}
void output(int s,int a[]){
  for(int i=0;i<s;i++) printf("%d ",a[i]);
}
int main(void){
   int a[1000],n;
   scanf("%d",&n);
   input(n,a);
   for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]==a[j]){
            for(int k=j;k<n-1;k++) a[k]=a[k+1];
            n--;
            j--;
        }
    }
   }
   output(n,a);
}
