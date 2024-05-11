#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
long long c[10];
int n;
void inputGraph(){
    for(int i=1;i<=(n-1);i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par,int color){
    c[color]++;
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex,!color);
    }
}
int main(void){
    cin>>n;
    inputGraph();
    dfs(1,0,0);
    cout<<1LL*((c[0]*c[1])-(n-1))<<endl;
}