#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>graph[N];
vector<int>f;
bool vis[N];
int deg[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
}
void dfs(int vertex,int par){
    vis[vertex]=true;
    f.push_back(vertex);
    //cout<<vertex<<" ";
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        dfs(i,vertex);
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            f.clear();
            dfs(i,-1);
            bool ans=true;
            for(auto& v:f) ans&= (deg[v]==2); 
            if(ans) cnt++;
        }
    }
    //for(int i=1;i<=n;i++) cout<<i<<" "<<deg[i]<<endl;
    cout<<cnt<<endl;
}