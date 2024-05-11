#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
int n,m;
int depth[N],height[N];
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par){
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        depth[i]=depth[vertex]+1;
        dfs(i,vertex);
        height[vertex]=max(height[vertex],height[i]+1);
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<"Node "<<i<<": "<<depth[i]<<" "<<height[i]<<endl;
    }
}