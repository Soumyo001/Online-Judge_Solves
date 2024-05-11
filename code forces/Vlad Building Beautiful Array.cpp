#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    int even=0,odd=0;
    int mini=INT_MAX;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i] & 1) ++odd;
        else ++even;
        mini=min(mini,v[i]);
    }
    //cout<<even<<" "<<odd<<endl;
    if(even == n || odd == n  || mini & 1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}