#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>> graph[N];
bool visited[N];
int dist[N];
int n,m,s;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
}
void dijkstra(){
    memset(dist,1e9+9,sizeof(dist));
    multiset<pair<int,int>> m;
    m.insert({0,s});
    dist[s]=0;
    while(!m.empty()){
        int vertex=m.begin()->second;
        int vertex_dist=m.begin()->first;
        m.erase(m.begin());
        if(visited[vertex]) continue;
        visited[vertex] = true;
        for(auto& i: graph[vertex]){
            if(dist[vertex] + i.second < dist[i.first]){
                dist[i.first] = dist[vertex] + i.second;
                m.insert({dist[i.first], i.first});
            }
        }
    }
}
void printDist(){
    for(int i=1;i<=n;i++) cout<<i<<" "<<dist[i]<<endl;
}
int main(void){
    cin>>n>>m>>s;
    inputGraph();
    dijkstra();
    printDist();
}