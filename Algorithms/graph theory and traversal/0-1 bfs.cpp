#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<pair<int,int>> graph[N];
vector<int>level(N,INT_MAX);
int n,m;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
}
void bfs(int source){
    deque<int>dq;
    dq.push_back(source);
    level[source]=0;
    while(!dq.empty()){
        int vertex=dq.front();dq.pop_front();
        for(const auto& i:graph[vertex]){
            if(level[i.first]>level[vertex]+i.second){
                level[i.first]=level[vertex]+i.second;
                if(i.second) dq.push_back(i.first);
                else dq.push_front(i.first);
                //cout<<i.first<<" "<<level[i.first]<<endl;
            }
        }
    }
}
void printLevel(){
    if(level[0] != INT_MAX) cout<<"Level of "<<0<<" from source is "<<level[0]<<endl;
    for(int i=1;i<=n;i++) cout<<"Level of "<<i<<" from source is "<<level[i]<<endl;
}
int main(void){
    int s;
    cin>>n>>m>>s;
    inputGraph();
    bfs(s);
    printLevel();
}