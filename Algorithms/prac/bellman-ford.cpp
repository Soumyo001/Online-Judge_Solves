#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dist[N],parent[N];
int n,m,s;
struct Edge{
    int u,v,wt;
};
vector<Edge>edges;
void bellman_ford(int source){
    dist[source]=0;
    for(int i=0;i<n-1;i++){
        for(auto& i:edges){
            if(dist[i.u]!=numeric_limits<int>::max() && dist[i.v]>dist[i.u]+i.wt){
                dist[i.v]=dist[i.u]+i.wt;
                parent[i.v]=i.u;
            }
        }
    }
    int node=-1;
    for(auto& i:edges){
        if(dist[i.u]!=numeric_limits<int>::max() && dist[i.v]>dist[i.u]+i.wt){
            node=i.v;break;
        }
    }
    if(node!=-1){
        vector<int>cycleN;
        int tempN=node;cycleN.push_back(tempN);
        node=parent[node];
        while(tempN!=node){
            cycleN.push_back(node);
            node=parent[node];
        }
        reverse(cycleN.begin(),cycleN.end());
        for(auto& i:cycleN) cout<<i<<" ";
        cout<<endl;
    }else{
        cout<<"No Neg Cycles"<<endl;
        for(int i=0;i<n;i++) cout<<"dist from "<<source<<" to "<<i<<" is "<<dist[i]<<endl;
    }
}
int main(void){
    cin>>n>>m>>s;
    edges.resize(m+1);
    for(int i=0;i<m;i++) cin>>edges[i].u>>edges[i].v>>edges[i].wt;
    for(int i=1;i<=n;i++) dist[i]=numeric_limits<int>::max();
    bellman_ford(s);
}