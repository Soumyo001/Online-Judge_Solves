#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
bool vis[N];
int n,m;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
bool dfs(int vertex,int par){
    vis[vertex]=true;
    bool isLoopExist=false;
    for(auto& i:graph[vertex]){
        if(vis[i] && i==par) continue;
        if(vis[i]) return true;
        isLoopExist |= dfs(i,vertex);
    }
    return isLoopExist;
}
int main(void){
    cin>>n>>m;
    inputGraph();
    bool isLoopExist=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,0)) {isLoopExist=true;break;}
            //isLoopExist |= dfs(i,i==1?0:i);
        }
    }
    cout<<isLoopExist<<endl;
}