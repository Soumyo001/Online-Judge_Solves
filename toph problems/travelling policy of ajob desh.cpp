#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
vector<int> graph[N],rev_graph[N];
int dist[N],rev_dist[N];
int status[N],rev_status[N];
int n,m,c,q;
void clear(){
    for(int i=0;i<n;i++) graph[i].clear(),rev_graph[i].clear();
}
void inputGraph(){
    clear();
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
}
void initiStatus(){
    for(int i=0;i<n;i++){
        status[i]=rev_status[i]=1;
        dist[i]=rev_dist[i]=INT_MAX;
    }
}
void bfs(int source){
    initiStatus();
    queue<int>q;
    dist[source]=0;
    rev_dist[source]=0;
    q.push(source);
    status[source]=2;
    while(!q.empty()){
        int val=q.front();q.pop();
        status[val]=3;
        for(auto& i:graph[val]){
            if(status[i]==1){
                q.push(i);
                status[i]=2;
                dist[i]=dist[val]+1;
            }
        }
    }
    q.push(source);
    rev_status[source]=2;
    while(!q.empty()){
        int val=q.front();q.pop();
        rev_status[val]=3;
        for(auto& i:rev_graph[val]){
            if(rev_status[i]==1){
                q.push(i);
                rev_status[i]=2;
                rev_dist[i]=rev_dist[val]+1;
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>c>>q;
        inputGraph();
        bfs(c);
        cout<<"Case "<<i<<":"<<endl;
        while(q--){
            int a,b;cin>>a>>b;
            if(dist[b]==INT_MAX || rev_dist[a]==INT_MAX) cout<<"Not possible to go from "<<a<<" to "<<b<<"."<<endl;
            else cout<<"The shortest distance from "<<a<<" to "<<b<<" is "<<dist[b]+rev_dist[a]<<"."<<endl;
        }
    }
}