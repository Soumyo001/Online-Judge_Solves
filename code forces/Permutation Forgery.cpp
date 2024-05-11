#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    reverse(v.begin(),v.end());
    for(auto& i:v) cout<<i<<" ";cout<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}