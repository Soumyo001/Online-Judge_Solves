#include<bits/stdc++.h>
using namespace std;
void input(int a[],int n){
   for(int i=0;i<n;i++) cin>>a[i];
}
int main(void){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int n,count=0;
    cin>>n;
    int arr[n];
    input(arr,n);
    sort(arr+0,arr+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           if(arr[i]==arr[j]) count++;
        }
    }
    n-=count;
    cout<<n<<endl;
  }
}
