#include<stdio.h>
void reverse(int *arr,int n){
  int temp;
  for(int i=0,j=1;i<n/2;i++,j++){
    temp=*(arr+i);
    *(arr+i)=*(arr+n-j);
    *(arr+n-j)=temp;
  }
}
int main(void){
  int arr[9]={1,2,3,4,5,6,7,8,9};
  reverse(arr,9);
  for(int i=0;i<9;i++){
    printf("%d  ",arr[i]);
  }

}
