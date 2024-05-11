#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>> graph[N];
int dist[N];
bool visited[N];
int n,m,src;
void initGraph(){
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
    //for(int i=1;i<=n;i++) dist[i]=numeric_limits<int>::max();
    memset(dist,1e9+5,sizeof(dist));
}
void dijkstra(){
    multiset<pair<int,int>> s;
    s.insert({0,src});
    dist[src]=0;
    while(!s.empty()){
        int vertex=s.begin()->second;
        int vertex_dist=s.begin()->first;
        s.erase(s.begin());
        if(visited[vertex]) continue;
        visited[vertex]=true;
        for(auto& i:graph[vertex]){
            if(dist[i.first]>dist[vertex]+i.second){
                dist[i.first]=dist[vertex]+i.second;
                s.insert({dist[i.first],i.first});
            }
        }
    }
}
void printDist(){
    for(int i=1;i<=n;i++) cout<<"dist from "<<src<<" to "<<i<<" is "<<dist[i]<<endl;
}
int main(void){
    cin>>n>>m>>src;
    initGraph();
    dijkstra();
    printDist();
}