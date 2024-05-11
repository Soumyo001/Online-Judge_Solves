#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
vector<pair<int,int>> graph[N],rev_graph[N];
long long dist[N],rev_dist[N];
int vis[N];
void Clear(){
    for (int i = 1; i <= n; i++)
    {
        graph[i].clear();
        rev_graph[i].clear();
    }
}
void inputGraph(){
    Clear();
    for(int i=1;i<=m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        rev_graph[v].push_back({u,wt});
    }
}
void initiStatus(long long dist[]){
    for(int i=1;i<=n;i++){
        dist[i]=LLONG_MAX;
        vis[i]=0;
    }
}
void dijkstra(int source,vector<pair<int,int>> Graph[],long long dist[]){
    initiStatus(dist);
    multiset<pair<long long,int>> s;
    s.insert({0,source});
    dist[source]=0;
    while(s.size()){
        auto node=s.begin();
        int vertex=node->second;
        long long vertex_dist=node->first;    
        s.erase(s.begin());
        if(vis[vertex]) continue;
        vis[vertex]=1;
        for(const auto& i:Graph[vertex]){
            if(dist[i.first]>dist[vertex]+i.second){
                dist[i.first]=dist[vertex]+i.second;
                s.insert({dist[i.first],i.first});
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int x,q;
        cin>>n>>m>>x>>q;
        inputGraph();
        dijkstra(x,graph,dist);
        dijkstra(x,rev_graph,rev_dist);
        cout<<"Case "<<i<<":"<<endl;
        while(q--){
            int s,t;cin>>s>>t;
            if(dist[t]==LLONG_MAX || rev_dist[s]==LLONG_MAX) cout<<"Be seeing ya, John"<<endl;
            else cout<<dist[t]+rev_dist[s]<<endl;
        }
    }
}
