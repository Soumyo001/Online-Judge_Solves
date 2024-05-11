#include<bits/stdc++.h>
using namespace std;
int main(void){
 int t;
 cin>>t;
 for(int i=0;i<t;i++){
 int arr[100];
 int n,c=0;
 cin>>n;
 for(n;n!=0;n/=10,c++){
    arr[c]=n%10;
 }
 for(int i=0;i<c-1;i++){
   for(int j=i+1;j<c;j++){
    if(arr[i]<arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
   }
 }
 for(int i=0;i<c;i++) cout<<arr[i];
 cout<<endl;
 }
}
