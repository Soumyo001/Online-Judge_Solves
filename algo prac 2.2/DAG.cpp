#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>> graph[N];
stack<int> st;
bool visited[N];
int n,m,dist[N];
vector<int> sources;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
}
void top_sort(int vertex){
    visited[vertex] = true;
    for(auto& i:graph[vertex]){
        if(!visited[i.first]) top_sort(i.first);
    }
    st.push(vertex);
}
void DAG(){
    for(int i=1;i<=n;i++) dist[i]=numeric_limits<int>::max();
    for(auto& i:sources) dist[i]=0;
    while(!st.empty()){
        int v=st.top();st.pop();
        for(auto& i:graph[v]){
            if(dist[i.first] > dist[v] + i.second && dist[v]!=numeric_limits<int>::max()) dist[i.first] = dist[v] + i.second;
        }
    }
}
void printDist(){
    for(int i=1;i<=n;i++) cout<<i<<" "<<(dist[i]==numeric_limits<int>::max() ? -1 : dist[i])<<endl;
}
int main(void){
    cin>>n>>m;
    inputGraph();
    for(int i=1;i<=n;i++) if(!visited[i]) sources.push_back(i),top_sort(i);
    DAG();
    printDist();
}