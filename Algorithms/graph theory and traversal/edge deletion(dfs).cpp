#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
int subtree_sum[N];
int val[N];
int n,m;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par){
    subtree_sum[vertex]+=val[vertex];
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
        subtree_sum[vertex]+=subtree_sum[i];
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    for(int i=1;i<=n;i++) {
        int a;cin>>a;
        val[i]=a;
    }
    dfs(1,0);
    long long mx=LLONG_MIN;
    for(int i=2;i<=n;i++){
        //mx=max(mx,subtree_sum[i]*(subtree_sum[1]-subtree_sum[i]));
        int part1=subtree_sum[i];
        int part2=subtree_sum[1]-subtree_sum[i];
        mx=max(mx,1LL*part1*part2);
    }
    cout<<mx<<endl;
}