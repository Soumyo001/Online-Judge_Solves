#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N],col_graph[N];
int c[N],c_dist[N],vis[N];
long long dist[N];
int n,d;
void Clear(){
    for(int i=1;i<=n;i++){
        graph[i].clear();
        col_graph[i].clear();
        c[i]=vis[i]=c_dist[i]=0;
        dist[i]=LLONG_MAX;
    }
}
void inputGraph(){
    Clear();
    for(int i=1;i<n;i++){
        int a;cin>>a;
        graph[a].push_back(i+1);
        graph[i+1].push_back(a);
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        col_graph[c[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>c_dist[i];
}
void dijkstra(int source){
    multiset<pair<long long,int>> m;
    m.insert({0,source});
    dist[source]=0;
    while(!m.empty()){
        int vertex=m.begin()->second;
        long long vertex_dist=m.begin()->first;
        m.erase(m.begin());
        if(vis[vertex]) continue;
        vis[vertex]=1;
        for(auto& i:col_graph[c[vertex]]){
            if(i==vertex) continue;
            if(dist[i]>dist[vertex]+c_dist[vertex]){
                dist[i]=dist[vertex]+c_dist[i];
                m.insert({dist[i],i});
            }
        }
        for(auto& i:graph[vertex]){
            if(dist[i]>dist[vertex]+d){
                dist[i]=dist[vertex]+d;
                m.insert({dist[i],i});
            }
        }
    }
}
void solve(){
    cin>>n>>d;
    inputGraph();
    int s,t;cin>>s>>t;
    dijkstra(s);
    cout<<dist[t]<<endl;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}