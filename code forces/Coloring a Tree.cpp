#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
int color[N],c[N];
bool vis[N]={false};
int n,step=0;
void inputGraph(){
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
    for(int i=1;i<=n;i++) cin>>color[i];
}
void dfs2(int vertex,int par,int color){
    c[vertex]=color;
    for(auto& i:graph[vertex]) if(i!=par) dfs2(i,vertex,color);
}
void dfs(int vertex,int par){
    if(color[vertex]!=c[vertex] && !vis[vertex]){
        ++step;
        //cout<<c[vertex]<<" "<<color[vertex]<<endl;
        dfs2(vertex,par,color[vertex]);
        vis[vertex]=true;
    }
    for(auto& i:graph[vertex]) if(i!=par) dfs(i,vertex);
}
int main(void){
    cin>>n;inputGraph();
    dfs(1,0);
    cout<<step<<endl;
}