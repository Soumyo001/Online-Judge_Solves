#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>>graph[N];
int dist[N];
stack<int>st;
bool visited[N];
int n,m,s;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
}
void topological_sort(int vertex){
    visited[vertex]=true;
    for(auto& i:graph[vertex]){
        if(!visited[i.first]) topological_sort(i.first);
    }
    st.push(vertex);
}
void DAG(){
    for(int i=1;i<=n;i++) dist[i]=INT_MAX;
    dist[s]=0;
    while(!st.empty()){
        int u=st.top();
        st.pop();
        for(auto& i:graph[u])
            if(dist[i.first] > dist[u]+i.second ) dist[i.first] = dist[u]+i.second;
    }
}
void printDist(){
    for(int i=1;i<=n;i++) cout<<i<<" "<<dist[i]<<endl;
}
int main(void){
    cin>>n>>m>>s;
    inputGraph();
    for(int i=1;i<=n;i++) if(!visited[i]) topological_sort(i);
    DAG();
    printDist();
}