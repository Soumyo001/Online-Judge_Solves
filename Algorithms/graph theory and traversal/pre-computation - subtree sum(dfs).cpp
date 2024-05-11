#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
vector<int>graph[N];
int subtree_sum[N],even_ct[N];
int n,m;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par){
    if(!(vertex & 1)) even_ct[vertex]++;
    subtree_sum[vertex]+=vertex;
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
        subtree_sum[vertex]+=subtree_sum[i];
        even_ct[vertex]+=even_ct[i];
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<i<<": "<<subtree_sum[i]<<" "<<even_ct[i]<<endl;
    int q;cin>>q;
    while(q--){
        int v;cin>>v;
        cout<<subtree_sum[v]<<" "<<even_ct[v]<<endl;
    }
}