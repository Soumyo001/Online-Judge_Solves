#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<pair<int,int>> graph[N];
int vis[N],dist[N];
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
}
void dijkstra(int source){
    memset(dist,1e9+10,sizeof(dist));
    set<pair<int,int>> s;
    s.insert({0,source});
    dist[source]=0;
    while(!s.empty()){
        auto node=s.begin();
        int vertex=node->second;
        int vertex_dis=node->first;
        s.erase(s.begin());
        if(vis[vertex]) continue;
        vis[vertex]=1;
        for(const auto& i:graph[vertex]){
            int child_vertex=i.first;
            int wt=i.second;
            if(dist[vertex]+wt<dist[child_vertex]){
                dist[child_vertex]=dist[vertex]+wt;
                s.insert(make_pair(dist[child_vertex],child_vertex));
            }
        }
    }
}
void printShortestCost(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++) cout<<"Shortest Cost from "<<1<<" to "<<i<<" is "<<dist[i]<<endl;
}
int main(void){
    int n,m;cin>>n>>m;
    inputGraph(m);
    dijkstra(1);
    printShortestCost(n);
}