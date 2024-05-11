#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
vector<int> govt;
vector<int> comp;
bool vis[N];
int n,m,k,gov[1010],outD[N],c=0;
void inputGraph(){
    for(int i=0;i<k;i++){
        int x;cin>>x;govt.push_back(x);++gov[x];
    }
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        ++outD[u];
    }
}
void dfs(int vertex,int& edges){
    vis[vertex]=true;
    edges+=outD[vertex];
    ++c;
    for(auto& i:graph[vertex]) if(!vis[i]) dfs(i,edges);
}
int main(void){
    cin>>n>>m>>k;
    inputGraph();
    int ans=0;
    int mx=INT_MIN;
    int flag=1,temp;
    for(int i=1;i<=n;i++){
        if(!vis[i] && !govt[i]){
            if(graph[i].empty()){
                comp.push_back(i);continue;
            }
            int edges=0;
            c=0;
            dfs(i,edges);
            mx=max(mx,c);
            if(!flag)temp=c;
            ans+=(((c*(c-1))/2)-edges);
            flag=0;
        }
    }

}