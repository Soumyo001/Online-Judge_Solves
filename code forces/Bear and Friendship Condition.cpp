#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<int>graph[N];
int d[N];
bool vis[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        d[u]++;
        d[v]++;
    }
}
void dfs(int vertex,int par,long long& cd,long long& v){
    vis[vertex]=true;
    cd+=d[vertex];
    v++;
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        dfs(i,vertex,cd,v);
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            long long c_degree=0,c_vertex=0;
            dfs(i,0,c_degree,c_vertex);
            if(1LL*c_degree!=c_vertex*(c_vertex-1)*1LL){
                cout<<"NO"<<endl;return 0;
            }
        }
    }
    cout<<"YES\n";
}