#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int>graph[N];
vector<int> c;
vector<vector<int>> cc;
int n,m,city=0;
bool vis[N];
void inputGraph(){
    for(int i=0;i<=n;i++) graph[i].clear(),vis[i]=false;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    city=0;
    c.clear();cc.clear();
}
void dfs(int vertex){
    vis[vertex] = true;
    //c.push_back(vertex);
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        dfs(i);
    }
}
int main(void){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        inputGraph();
        for(int i=0;i<n;i++){
            if(!vis[i]){
                city++;
                dfs(i);
                // cc.push_back(c);
                // c.clear();
            }
        }
        cout<<city-1<<endl;
    }
}