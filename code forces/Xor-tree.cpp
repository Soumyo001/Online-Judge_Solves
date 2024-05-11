#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
int n;
vector<int> nodes;
int initi[N],goal[N];
void inputGraph(){
    for(int i=1;i<=(n-1);i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs2(int vertex,int count,int par){
    if(count==2) {initi[vertex]^=1;count=0;}
    ++count;
    for(auto& i:graph[vertex]) if(i!=par) dfs2(i,count,vertex);
}
void dfs(int vertex,int par,int x=0,int y=0){
    if(initi[vertex]^x) nodes.push_back(vertex),x^=1;
    for(auto& i:graph[vertex]) if(i!=par) dfs(i,vertex,y,x);
}
int main(void){
    cin>>n;
    inputGraph();
    for(int i=1;i<=n;i++) cin>>initi[i];
    for(int i=1;i<=n;i++) cin>>goal[i],initi[i]^=goal[i];
    dfs(1,0);
    cout<<nodes.size()<<endl;
    for(auto& i:nodes) cout<<i<<endl;
}