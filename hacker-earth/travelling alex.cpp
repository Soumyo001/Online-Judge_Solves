#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
vector<int> value;
int inT[N],outT[N];
long long dist=0;
int n;
void Clear(){
    for(int i=1;i<=n;i++) graph[i].clear(),inT[i]=outT[i]=0;
    value.clear();
    dist=0;
}
void inputGraph(){
    Clear();
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par){
    inT[vertex]=dist++;
    value.push_back(vertex);
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
    }
    outT[vertex]=dist++;
}
int main(void){
    int t;cin>>t;
    while(t--){
        cin>>n;
        inputGraph();
        dfs(1,0);
        cout<<inT[value[value.size()-1]]<<endl;
    }
}
