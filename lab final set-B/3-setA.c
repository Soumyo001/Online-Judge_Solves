#include<stdio.h>
int fact(int *p){
  static int temp=1;
  for(int i=1;i<=*p;i++){
    temp*=i;
  }
  return temp;
}
int main(void){
  int n;
  scanf("%d",&n);
  printf("%d",fact(&n));
}
