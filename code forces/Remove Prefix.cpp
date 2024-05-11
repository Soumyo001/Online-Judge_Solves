#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    set<int> s;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    bool yes=false;
    for(int i=n-1;i>=0;i--){
        if(s.count(v[i])){
            yes=true;
            cout<<i+1<<endl;break;
        }
        s.insert(v[i]);
    }
    if(!yes) cout<<0<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}