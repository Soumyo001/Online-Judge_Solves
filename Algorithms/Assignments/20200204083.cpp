#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N],dist[N];
int n,m,s;
struct Edge{
    int src,dest,wt;
};
vector<Edge> edges;
void printPath(){
    for(int i=0;i<n;i++){
        if(i==s) {
            cout<<"path cost = 0"<<endl<<endl;
            continue;
        }
        int node=i;
        vector<int> _path;
        while(node!=s){
            _path.push_back(node);
            node=parent[node];
        }
        _path.push_back(node);
        reverse(_path.begin(),_path.end());
        cout<<"Path Cost from "<<s<<" to "<<i<<" is "<<dist[i]<<endl;
        for(auto& j:_path) cout<<j<<(j==i ? "\n":"->");
        cout<<endl;
    }
}
void bellman_ford(){
    dist[s]=0;
    for(int i=0;i<n-1;i++){
        for(auto& i:edges){
            if(dist[i.src]!=numeric_limits<int>::max() && dist[i.dest]>dist[i.src]+i.wt){
                dist[i.dest]=dist[i.src]+i.wt;
                parent[i.dest]=i.src;
            }
        }
    }
    for(auto& i:edges){
        if(dist[i.src]!=numeric_limits<int>::max() && dist[i.dest]>dist[i.src]+i.wt) return;
    }
    printPath();
}
int main(void){
    cin>>n>>m>>s;
    edges.resize(m+1);
    for(int i=0;i<m;i++) cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
    for(int i=0;i<n;i++) dist[i]=numeric_limits<int>::max();
    bellman_ford();
}