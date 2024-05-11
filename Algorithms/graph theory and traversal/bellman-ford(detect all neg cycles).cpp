#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dist[N],parent[N];
struct Edge{
    int src,dest,wt;
};
int n,m,s;
vector<Edge> edges;
void find_cycle(int node){
    vector<int>cycleN;
    cycleN.push_back(node);
    int tempN=node;
    node=parent[node];
    while (tempN!=node)
    {
        cycleN.push_back(node);
        node=parent[node];
    }
    reverse(cycleN.begin(),cycleN.end());
    for(auto& i:cycleN) cout<<i<<" ";
    cout<<endl;
}
void bellman_ford(int source){
    dist[source]=0;
    bool flag=true;
    for(int i=0;i<n-1;i++){
        if(!flag) break;
        flag=false;
        for(auto& i:edges){
            if(dist[i.src]!=numeric_limits<int>::max() && dist[i.dest]>dist[i.src]+i.wt){
                dist[i.dest]=dist[i.src]+i.wt;
                parent[i.dest]=i.src;
                flag=true;
            }
        }
    }
    for(auto& i:edges){
        if(dist[i.src]!=numeric_limits<int>::max() && dist[i.dest]>dist[i.src]+i.wt){
            find_cycle(i.dest);
        }
    }
}
int main(void){
    cin>>n>>m>>s;
    edges.resize(m+1);
    for(int i=0;i<m;i++) cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
    for(int i=0;i<n;i++) dist[i]=numeric_limits<int>::max();
    bellman_ford(s);
}