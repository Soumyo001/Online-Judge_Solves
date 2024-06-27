#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int> graph[N];
vector<vector<int>> cycles;
vector<int> cycle;
int vis[N];
int parent[N];
int cn=0;
int n,m;
void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void captureCycle(int vertex,int par){
    cycle.clear();
    while(vertex!=par){
        cycle.push_back(par);
        par=parent[par];
    }
    cycle.push_back(vertex);
    reverse(cycle.begin(),cycle.end());
    cycles.push_back(cycle);
}

void dfs(int vertex,int par){
    parent[vertex]=par;
    vis[vertex]=1; //1 for processing node
    for(auto& i:graph[vertex]){
        if(i==par && vis[i]==1) continue;
        if(vis[i]==1){
            ++cn;
            captureCycle(i,vertex);
            continue;
        }
        if(vis[i]==0) dfs(i,vertex); //0 for unactive node
    }
    vis[vertex]=2; //2 for completed node
}

int main(void){
    cin>>n>>m;
    inputGraph();
    dfs(1,0);
    cout<<cn<<'\n';
    for(auto& i:cycles){
        for(auto& j:i) cout<<j<<" ";
        cout<<'\n';
    }
}