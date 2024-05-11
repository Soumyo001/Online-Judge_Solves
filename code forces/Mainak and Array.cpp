#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n,0);
    int mx=INT_MIN;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++) mx=max(mx,v[(i-1+n)%n]-v[i]);
    for(int i=0;i<n-1;i++) mx=max(mx,v[n-1]-v[i]);
    for(int i=1;i<n;i++) mx=max(mx,v[i]-v[0]);
    cout<<mx<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}