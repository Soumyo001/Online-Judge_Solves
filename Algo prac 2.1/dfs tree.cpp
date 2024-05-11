#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
int depth[N],height[N];
void inputGraph(int number_of_edges){
    for(int i=0;i<number_of_edges;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par){
    cout<<vertex<<" ";
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        depth[i]=depth[vertex]+1;
        dfs(i,vertex);
        height[vertex]=max(height[vertex],height[i]+1);
    }
}
void depth_height(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++) cout<<i<<" "<<depth[i]<<" "<<height[i]<<endl;
}
int main(void){
    int n,m,source;
    cin>>n>>m>>source;
    inputGraph(m);
    dfs(source,-1);cout<<endl;
    depth_height(n);
}