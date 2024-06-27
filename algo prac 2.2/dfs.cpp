#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> graph[N];
int depth[N],height[N],subtree_sum[N],even_ct[N];
int v,e,s;
void inputGraph(){
    for(int i=0;i<e;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par){
    cout<<vertex<<" ";
    subtree_sum[vertex]=vertex;
    even_ct[vertex]=(vertex&1? 0:1);
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        depth[i]=depth[vertex]+1;
        dfs(i,vertex);
        height[vertex]=max(height[i]+1,height[vertex]);
        subtree_sum[vertex]+=subtree_sum[i];
        even_ct[vertex]+=even_ct[i];
    }
}
void printData(){
    for(int i=1;i<=v;++i){
        cout<<"Node "<<i<<": "<<depth[i]<<" "<<height[i]<<" "<<subtree_sum[i]<<" "<<even_ct[i]<<"\n";
    }
}
int main(void){
    cin>>v>>e>>s;
    inputGraph();
    dfs(s,(s==1?0:-1));
    cout<<"\n";
    printData();
}