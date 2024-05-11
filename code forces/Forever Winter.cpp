#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;int deg[N];
void inputGraph(){
    for(int i=0;i<=n;i++) deg[i]=0;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;++deg[a];++deg[b];
    }
}
void solve(){
    cin>>n>>m;
    inputGraph();
    map<int,int> m;
    for(int i=1;i<=n;i++) ++m[deg[i]];
    int x=-1,xF=-1,xyF=-1;
    if(m.size()==3){
        for(auto& i:m){
            if(i.first==1) xyF=i.second;
            else if(i.second==1) x=i.first;
            //cout<<i.first<<" "<<i.second<<endl;
        }
    }else{
        for(auto& i:m){
            if(i.first==1) xyF=i.second;
            else if(i.second>1) x=i.first;
            //cout<<i.first<<" "<<i.second<<endl;
        }
    }
    cout<<x<<" "<<xyF/x<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}