#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=1e9+9;
vector<int> graph[N];
bool vis[N];
int status[N],level[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void initiStatus(){
    for(int i=1;i<=n;i++) status[i]=1,level[i]=inf;
}
void bfs(int source){
    initiStatus();
    queue<int>q;
    q.push(source);
    status[source]=2;
    level[source]=0;
    while(!q.empty()){
        int val=q.front();q.pop();
        cout<<val<<" ";
        status[val]=3;
        for(auto& i:graph[val]){
            if(status[i]==1){
            //if(level[i]==inf){
                q.push(i);
                status[i]=2;
                level[i]=level[val]+1;
            }
        }
    }
}
void showLevel(){
    for(int i=1;i<=n;i++) cout<<i<<" "<<level[i]<<endl;
}
void dfs(int vertex){
    cout<<vertex<<" ";
    vis[vertex]=true;
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        dfs(i);
    }
}
int main(void){
    int source;
    cin>>n>>m>>source;
    inputGraph();
    bfs(source);cout<<endl;
    showLevel();
    dfs(source);cout<<endl;
}