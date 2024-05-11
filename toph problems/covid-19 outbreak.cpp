#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
vector<pair<int,long long>>graph[N];
int n;
long long val[N];
void inputGraph(){
    for(int i=1;i<=(n-1);i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,1LL*wt});
        graph[v].push_back({u,1LL*wt});
    }
}
void dfs(int vertex,int par){
    //long long ans=val[vertex];
    for(auto& i:graph[vertex]){
        if(i.first==par) continue;
        dfs(i.first,vertex);
        val[vertex]+=min(i.second,val[i.first]);
    }
    //return ans;
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int z;
    cin>>n>>z;
    inputGraph();
    for(int i=1;i<=n;i++) cin>>val[i];
    dfs(z,0);
    cout<<val[z]<<endl;
}