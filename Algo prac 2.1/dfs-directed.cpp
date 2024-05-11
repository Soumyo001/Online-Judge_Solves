#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
int vis[N],depth[N],height[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
    }
}
void dfs(int vertex){
    vis[vertex]=1;
    cout<<vertex<<" ";
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        depth[i]=depth[vertex]+1;
        dfs(i);
        height[vertex]=max(height[vertex],height[i]+1);
    }
}
void check(){
    for(int i=1;i<=n;i++) cout<<i<<" "<<depth[i]<<" "<<height[i]<<endl;
}
int main(void){
    int source;cin>>n>>m>>source;
    inputGraph();
    dfs(source);cout<<endl;
    check();
}