#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        long long a[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a+0,a+n);
        for(int i=1;i<n;i++) a[i]+=a[i-1];
        while(q--){
            int lo=0,hi=n-1;
            long long k;cin>>k;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(a[mid]<k) lo=mid+1;
                else hi=mid-1;
            }
            cout<<lo<<endl;
        }
    }
}