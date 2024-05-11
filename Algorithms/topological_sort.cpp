#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
bool visited[N];
stack<int> st;
int n,e,s;
void inputGraph(){
    for(int i=0;i<e;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        //graph[b].push_back(a);
    }
}
void dfs(int vertex){
    visited[vertex]=true;
    for(auto& i:graph[vertex]){
        if(visited[i]) continue;
        dfs(i);
    }
    st.push(vertex);
}
int main(void){
    cin>>n>>e>>s;
    inputGraph();
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}