#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7,inf=1e9+10;
int dist[N],vis[N],graph[N][N];
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int n,m,wt;cin>>n>>m>>wt;
        graph[n][m]=wt;
    }
}
void dijkstra(int source,int number_of_nodes){
    set<pair<int,int>> st;
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0){
        auto node=*st.begin();
        int vertex=node.second;
        int vertex_dis=node.first;
        st.erase(st.begin());
        if(vis[vertex]) continue;
        vis[vertex]=1;
        for(int i=1;i<=number_of_nodes;i++){
            if(graph[vertex][i]){
                int wt=graph[vertex][i];
                int child_vertex=i;
                if(dist[vertex]+wt<dist[child_vertex]){
                    dist[child_vertex]=dist[vertex]+wt;
                    st.insert({dist[child_vertex],child_vertex});
                }
            }
        }
    }
}
void showShortestCost(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        cout<<"Shortest cost for "<<i<<" is: "<<dist[i]<<endl;
    }
}
int main(void){
    memset(dist,inf,sizeof(dist));
    int n,e,s;cin>>n>>e>>s;
    inputGraph(e);
    dijkstra(s,n);
    showShortestCost(n);
}
