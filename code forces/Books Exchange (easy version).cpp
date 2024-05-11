#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> p(n+1);
    vector<int> ans(n);
    vector<bool> used(n+1,false);
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++){
        if(!used[i]){
            vector<int> d;
            used[i]=true;
            int curr=p[i];
            d.push_back(curr);
            while(curr != i){
                used[curr]=true;
                curr=p[curr];
                d.push_back(curr);
            }
            for(auto i:d) ans[i-1]=d.size();
        }
    }
    for(auto& i:ans) cout<<i<<" ";cout<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}