#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=1e9+9;
vector<pair<int,int>>graph[N];
stack<int> st;
bool visited[N];
int dist[N];
int n,m,s;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back(make_pair(v,wt));
    }
}
void topological_sort(int vertex){
    visited[vertex]=true;
    for(const auto& i:graph[vertex]){
        if(visited[i.first]) continue;
        topological_sort(i.first);
    }
    st.push(vertex);
}
void Clear(){
    for(int i=1;i<=n;i++) dist[i]=INT_MAX;
}
void dijkstra(){
    Clear();
    dist[s]=0;
    while (!st.empty())
    {
        int vertex=st.top();st.pop();
        for(const auto& i:graph[vertex]){
            if(dist[i.first]>dist[vertex]+i.second && dist[vertex] != INT_MAX){
                dist[i.first]=dist[vertex]+i.second;
            }
        }
    }
    
}
void printDist(){
    for(int i=1;i<=n;i++) dist[i]==INT_MAX? cout<<"dist from "<<s<<" to "<<i<<" is infinity"<<endl : cout<<"dist from "<<s<<" to "<<i<<" is "<<dist[i]<<endl;
}
int main(void){
    cin>>n>>m>>s;
    inputGraph();
    for(int i=1;i<=n;i++) if(!visited[i]) topological_sort(i);
    dijkstra();printDist();
}