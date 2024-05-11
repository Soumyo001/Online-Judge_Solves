#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
           int n;cin>>n;
    int k=n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0)k--;
    }
    if(k==0) cout<<"Bob"<<endl;
    else if(k&1) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    }
}