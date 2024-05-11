#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
vector<vector<int>> cc;
vector<int> cr_cc;
bool vis[N];
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int u,v,wt;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex){
    //cout<<vertex<<" ";
    cr_cc.push_back(vertex);
    vis[vertex]=1;
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        dfs(i);
    }
}
int main(void){
    int n,e;cin>>n>>e;
    inputGraph(e);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cr_cc.clear();
            dfs(i);
            cc.push_back(cr_cc);
        }
    }
    cout<<cc.size()<<endl;
    for(auto& i:cc){
        for(auto& j:i) cout<<j<<" ";
        cout<<endl;
    }
}