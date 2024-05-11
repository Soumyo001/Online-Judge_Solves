#include<bits/stdc++.h>
using namespace std;
int arr[110];
int main(void){
    int n,mx=INT_MIN;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];mx=(mx<arr[i] ? arr[i]:mx);
    }
    int sum=0;
    for(int i=1;i<=n;i++) sum+=(mx-arr[i]);
    cout<<sum;
}