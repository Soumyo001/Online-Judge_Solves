#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
vector<int> graph[N];
int value[N],status[N];
int n,m;
long long ans=0;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void intitiStatus(){
    for(int i=1;i<=n;i++) status[i]=1;
}
int bfs(int source){
    queue<int>q;
    q.push(source);
    status[source]=2;
    int mn=value[source];
    while(!q.empty()){
        int val=q.front();q.pop();
        mn=min(mn,value[val]);
        status[val]=3;
        for(auto& i:graph[val]){
            if(status[i]==1){
                q.push(i);
                status[i]=2;
            }
        }
    }
    return mn;
}
int main(void){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>value[i];
    inputGraph();
    intitiStatus();
    for(int i=1;i<=n;i++){
        if(status[i]==1){
            ans+=bfs(i);
        }
    }
   cout<<ans<<endl;
}