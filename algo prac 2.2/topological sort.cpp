#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
stack<int> st;
bool visited[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
    }
}
void top_sort(int vertex){
    visited[vertex] = true;
    for(auto& i:graph[vertex]){
        if(!visited[i]) top_sort(i);
    }
    st.push(vertex);
}
int main(void){
    cin>>n>>m;
    inputGraph();
    for(int i=1;i<=n;i++) if(!visited[i]) top_sort(i);
    while(!st.empty()){
        cout<<st.top()<<" ";st.pop();
    }
}

//topological sorts can only be applied to directed acyclic graphs