#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
vector<int> graph[N];
//int vis[N];
int n,m,x;
int c=0;
void clear(){
    for(int i=1;i<=n;i++) graph[i].clear();
}
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
    }
}
int dfs(int vertex){
    //vis[vertex]=1;
    for(auto& i:graph[vertex]){
        if(dfs(i)==0) return 1;
    }
    return 0;
}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        c=0;
        cin>>n>>m>>x;
        if(n==1) {cout<<"Case "<<i<<": "<<"No"<<endl;continue;}
        inputGraph();
        if(dfs(x)) cout<<"Case "<<i<<": "<<"Yes"<<endl;
        else cout<<"Case "<<i<<": "<<"No"<<endl;
        clear();
    }
}