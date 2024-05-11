#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
int status[N],level[N];
int s,n,e;
void inputGraph(){
    for(int i=0;i<e;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void multibfs(vector<int>& s){
    for(int i=1;i<=n;i++) status[i]=1;
    queue<int> q;
    for(auto& i:s) {q.push(i);status[i]=2;}
    while(!q.empty()){
        int v=q.front();q.pop();
        status[v]=3;
        for(auto& i:graph[v]){
            if(status[i]==1){
                q.push(i);
                status[i]=2;
                level[i]=level[v]+1;
            }
        }
    }
}
void printDist(){
    for(int i=1;i<=n;i++) cout<<i<<" "<<level[i]<<endl;
}
int main(void){
    cin>>n>>e>>s;
    vector<int> sources;
    sources.resize(s+1,0);
    for(int i=0;i<s;i++) cin>>sources[i];
    inputGraph();
    multibfs(sources);
    printDist();
}