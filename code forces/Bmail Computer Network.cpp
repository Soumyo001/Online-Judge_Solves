#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int> graph[N];
vector<int> ans;
int n;
void inputGraph(){
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
}
void dfs(int vertex,int par){
    ans.push_back(vertex);
    if(vertex==n){
        for(auto i:ans) cout<<i<<" ";
        exit(0);
    }
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
        ans.pop_back();
    }
}
int main(void){
    cin>>n;
    inputGraph();dfs(1,0);
}