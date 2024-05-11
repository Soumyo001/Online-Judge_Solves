#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int> graph[N];
int n;
long long subset[N];
void inputGraph(){
    for(int i=0;i<=n;i++) {graph[i].clear();subset[i]=0;}
    for(int i=1;i<=(n-1);i++){
        int a,b;cin>>a>>b;
        if(a>b) swap(a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}
void dfs(int vertex,int par){
    int flag=1;
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
        flag=0;
        subset[vertex]+=subset[i];
    }
    if(flag) subset[vertex]=1;
}
void solve(){
    cin>>n;
    inputGraph();
    int q;cin>>q;
    dfs(1,0);
    while(q--){
        int a,b;cin>>a>>b;
        cout<<subset[a]*subset[b]*1LL<<endl;
    }
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}