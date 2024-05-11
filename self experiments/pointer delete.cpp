#include<bits/stdc++.h>
using namespace std;
int main(void){
  int *p,a=10;
  p=&a;
  cout<<*p<<endl;
  cout<<p<<endl;
  cout<<&a<<endl;
  int arr[10]={1,2,3,4,5,6,7,8,9,10};//10000,10004,10008
  int *k;
  k=arr;
  for(int i=0;i<10;i++){
    cout<<*k;
    k++;
  }
  char ch[1000]={"Hello World"};
  char *c;
  c=ch;
  for(int i=0;i<strlen(ch);i++){
    cout<<*c;
    c++;
  }
}
