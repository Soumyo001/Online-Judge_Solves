#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>>graph[N];
int dist[N];
bool visited[N];
stack<int>st;
int n,m,s;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
}
void topSort(int vertex){
    visited[vertex]=true;
    for(auto& i:graph[vertex]){
        if(!visited[i.first]) topSort(i.first);
    }
    st.push(vertex);
}
void DAG(){
    memset(dist,1e9+5,sizeof(dist));
    dist[s]=0;
    while(!st.empty()){
        int vertex=st.top();st.pop();
        for(auto& i:graph[vertex]) if(dist[i.first]>dist[vertex]+i.second) dist[i.first]=dist[vertex]+i.second;
    }
}
void printDist(){
    for(int i=1;i<=n;i++) cout<<i<<" "<<dist[i]<<endl;
}
void solve(){
    inputGraph();
    topSort(s);
    DAG();
    printDist();
}
int main(void){
    cin>>n>>m>>s;
    solve();
}