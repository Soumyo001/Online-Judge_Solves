#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int> graph[N];
bool visited[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
bool _dfs_cycle(int vertex,int par){
    visited[vertex] = true;
    bool isCycle = false;
    for(auto& i:graph[vertex]){
        if(visited[i] && i==par) continue;
        if(visited[i]) return true;
        isCycle |= _dfs_cycle(i,vertex);
    }
    return isCycle;
}
int main(void){
    cin>>n>>m;
    inputGraph();
    bool cycle;
    for(int i=1;i<=n;i++) if(!visited[i]) if(_dfs_cycle(i,-1)) {cycle=true;break;}
    cout<<cycle;
}