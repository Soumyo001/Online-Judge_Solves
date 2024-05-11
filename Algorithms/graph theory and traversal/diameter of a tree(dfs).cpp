#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
int depth[N];
int n,m;
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
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    dfs(1,0);
    int node=-1;
    int max=INT_MIN;
    for(int i=1;i<=n;i++){
        if(max<depth[i]){
            max=depth[i];
            node=i;
        }
        depth[i]=0;
    }
    dfs(node,0);
    //cout<<*max_element(depth+1,depth+n+1)<<endl;
    for(int i=1;i<=n;i++) if(max<depth[i]) max=depth[i];
    cout<<max<<endl;
}