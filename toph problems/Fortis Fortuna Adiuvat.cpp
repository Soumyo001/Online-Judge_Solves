#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
vector<pair<int,int>> graph[N],rev_graph[N];
int vis[N];
long long dist[N],rev_dist[N];
void Clear(){
    for(int i=1;i<=n;i++){
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
void initiStatus(){
    for(int i=1;i<=n;i++){
        dist[i]=rev_dist[i]=LLONG_MAX;
        vis[i]=0;
    }
}
void dijkstra(int source){
    initiStatus();
    set<pair<long long,int>>s;
    s.insert({0,source});
    dist[source]=0;
    while(s.size()){
        auto node=s.begin();
        int vertex=node->second;
        int vertex_dist=node->first;
        s.erase(s.begin());
        if(vis[vertex]) continue;
        vis[vertex]=1;
        for(auto& i:graph[vertex]){
            if(dist[i.first]>dist[vertex]+i.second){
				//if(dist[i.first]!=LLONG_MAX) s.erase(s.find({dist[i.first],i.first}));
                dist[i.first]=dist[vertex]+i.second;
                s.insert({dist[i.first],i.first});
            }
        }   
    }
    for(int i=1;i<=n;i++) vis[i]=0;
    s.clear();
    s.insert({0,source});
    rev_dist[source]=0;
    while(s.size()){
        auto node=s.begin();
        int vertex=node->second;
        int vertex_dist=node->first;
        s.erase(s.begin());
        if(vis[vertex]) continue;
        vis[vertex]=1; 
        for(auto& i:rev_graph[vertex]){
            if(rev_dist[i.first]>rev_dist[vertex]+i.second){
				//if(rev_dist[i.first]!=LLONG_MAX) s.erase(s.find({rev_dist[i.first],i.first}));
                rev_dist[i.first]=rev_dist[vertex]+i.second;
                s.insert({rev_dist[i.first],i.first});
            }
        }
    }
}
int main(void){
	ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int x,q;
        cin>>n>>m>>x>>q;
        inputGraph();
        dijkstra(x);
		cout<<"Case "<<i<<":"<<endl;
        while(q--){
            int s,t;cin>>s>>t;
            if(dist[t]==LLONG_MAX || rev_dist[s]==LLONG_MAX) cout<<"Be seeing ya, John"<<endl;
            else cout<<dist[t]+rev_dist[s]<<endl;
        }
    }
}