#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<pair<int,int>>graph[N];
bool vis[N];
int n,m,ans=0,c[N],depth[N];
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
}
void dfs(int vertex, int dest, int color){
    vis[vertex]=true;
    if(vertex==dest){
            ++ans;return;
    }
    for(auto& i:graph[vertex]){
        if(vis[i.first] || i.second!=color) continue;
        dfs(i.first,dest,color);
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    int q;cin>>q;
    while(q--){
        ans=0;
        int u,v;cin>>u>>v;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++) {vis[j]=false;}
            dfs(u,v,i);
        }
        cout<<ans<<endl;
    }
}