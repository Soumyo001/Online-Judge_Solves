#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
int depth[N];
void inputGraph(int number_of_nodes){
    for(int i=1;i<=(number_of_nodes-1);i++){
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
    long long n;
    cin>>n;
    inputGraph(n);
    dfs(1,0);
    long long sum=n;
    for(int i=1;i<=n;i++) sum+=depth[i];
    cout<<sum;
}