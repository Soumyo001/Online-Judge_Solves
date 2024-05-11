#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
vector<int>graph[N];
bool vis[N];
int n,m;
vector<int>c;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        //if(u==v) continue;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex){
    vis[vertex]= true;
    c.push_back(vertex);
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        dfs(i);
    }
}
void bfs(int source){
    multiset<int> q;
    vis[source]=true;
    q.insert(source);
    while(!q.empty()){
        int v=*(q.begin());q.erase(q.begin());
        c.push_back(v);
        for(auto& i:graph[v]){
            if(vis[i]) continue;
            q.insert(i);vis[i]=true;
        }
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    //for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end());
    bfs(1);
    for(auto& i:c) cout<<i<<" ";
}