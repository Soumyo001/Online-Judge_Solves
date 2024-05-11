#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,nn=0;cin>>n;
    vector<int> v(n+1,0);
    vector<int>p;
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++) if(v[i-1]!=v[i])nn++,p.push_back(v[i]);
    if(nn==1){
        cout<<"Yes"<<endl;return;
    }else if(nn>2){
        cout<<"No"<<endl;return;
    }
    nn=0;int np=0;
    for(int i=1;i<=n;i++) {if(v[i]==p[0]) nn++;else np++;}
    if(nn==(n/2) || np==(n/2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}