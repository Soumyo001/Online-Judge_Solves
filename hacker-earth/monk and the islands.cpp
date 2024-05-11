#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
int status[N],dist[N];
int n,m;
void Clear(){
    for(int i=1;i<=n;i++) graph[i].clear();
}
void inputGraph(){
    Clear();
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void initiStatus(){
    for(int i=1;i<=n;i++) status[i]=1,dist[i]=0;
}
void bfs(int source){
    initiStatus();
    queue<int>q;
    q.push(source);
    status[source]=2;
    while(!q.empty()){
        int val=q.front();q.pop();
        status[val]=3;
        for(auto& i:graph[val]){
            if(status[i]==1){
                q.push(i);
                status[i]=2;
                dist[i]=dist[val]+1;
            }
        }
    }
}
int main(void){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        inputGraph();
        bfs(1);
        cout<<dist[n]<<endl;
    }
}