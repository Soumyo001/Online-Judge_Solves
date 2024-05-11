#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
bool visited[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex){
    visited[vertex]=true;
    for(auto& i:graph[vertex]){
        if(!visited[i]) dfs(i);
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    if(n<3 || m<3){
        cout<<"NO"<<endl;
        return 0;
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(m!=n){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"FHTAGN!"<<endl;
}