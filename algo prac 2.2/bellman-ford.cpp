#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,s;
struct Edge{
    int src,dest,wt;
};
vector<Edge> edges;
int dist[N],parent[N];
void inputGraph(){
    edges.resize(m);
    for(int i=0;i<m;i++) {
        cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
        parent[edges[i].dest] = edges[i].src;
    }
}
void printCycle(int node){
    vector<int> cycleS;
    cycleS.push_back(node);
    int temp=node;
    node = parent[node];
    while(temp != node){
        cycleS.push_back(node);
        node = parent[node];
    }
    //cycleS.push_back(node);
    reverse(cycleS.begin(), cycleS.end());
    for(auto& i:cycleS) cout<<i<<" ";
    cout<<endl;
}
void bellman_ford(int source){
    for(int i=0;i<=n;i++) dist[i]=INT_MAX;
    dist[source]=0;
    int flag=1;
    for(int i=0;i<n-1;i++){
        if(!flag) break;
        flag=0;
        for(auto& i:edges){
            if(dist[i.src] != INT_MAX && dist[i.dest] > dist[i.src] + i.wt){
                dist[i.dest] = dist[i.src] + i.wt;
                parent[i.dest] = i.src;
                flag=1;
            }
        }
    }
    for(auto& i:edges){
        if(dist[i.src] != INT_MAX && dist[i.dest] > dist[i.src] + i.wt) printCycle(i.dest);
    }
}
int main(void){
    cin>>n>>m>>s;
    inputGraph();
    bellman_ford(s);
}