#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int dist[N],parent[N];
bool visited[N];
struct Edges{
    int src,dest,wt;
};
vector<Edges>edges;
void bellman_ford(int s){
    dist[s]=0;
    visited[s]=true;
    bool flag=true;
    for(int i=0;i<n-1;i++){
        if(!flag) break;
        flag=false;
        for(auto& i:edges){
            if(dist[i.src]!=numeric_limits<int>::max() && dist[i.dest]>dist[i.src]+i.wt){
                visited[i.dest]=true;
                parent[i.dest]=i.src;
                dist[i.dest]=dist[i.src]+i.wt;
                flag=true;
            }
        }
    }
    int node=-1;
    for(auto& i:edges){
        if(dist[i.src]!=numeric_limits<int>::max() && dist[i.dest]>dist[i.src]+i.wt){
            node=i.dest;
            break;
        }
    }
    vector<int>cycle;
    if(node!=-1){
        int tempN=node;
        cycle.push_back(node);
        node=parent[node];
        while(tempN!=node){
            cycle.push_back(node);
            node=parent[node];
        }
    }
    reverse(cycle.begin(),cycle.end());
    for(auto& c:cycle) cout<<c<<" ";
    cout<<endl;
}
void printDist(){
    for(int i=1;i<=n;i++) cout<<i<<" "<<dist[i]<<endl;
}
int main(void){
    cin>>n>>m;
    edges.resize(m+1);
    for(int i=0;i<m;i++) cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
    for(int i=1;i<=n;i++) dist[i]=numeric_limits<int>::max();
    for(int i=1;i<=n;i++) if(!visited[i]) bellman_ford(i);
}