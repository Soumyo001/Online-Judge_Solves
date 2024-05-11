#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr+0,arr+n);
    for(int i=1;i<n;i++) arr[i]+=arr[i-1];
    for(int i=0;i<n;i++) arr[i]/=(i+1);
    int q;cin>>q;
    while(q--){
        int k;cin>>k;
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]<k) lo=mid+1;
            else hi=mid-1;
        }
        cout<<lo<<endl;
    }
}