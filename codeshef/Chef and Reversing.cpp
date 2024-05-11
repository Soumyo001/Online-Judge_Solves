#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<pair<int,int>>graph[N];
vector<int>level(N,INT_MAX);
int n,m;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back({v,0});
        graph[v].push_back({u,1});
    }
}
int bfs(){
    list<int> dq;
    dq.push_back(1);
    level[1]=0;
    while(!dq.empty()){
        int vertex=dq.front();dq.pop_front();
        for(const auto& i:graph[vertex]){
            if(level[i.first]>level[vertex]+i.second){
                level[i.first]=level[vertex]+i.second;
                if(i.second) dq.push_back(i.first);
                else dq.push_front(i.first);
            }
        }
    }
    return level[n]==INT_MAX?-1:level[n];
}
int main(void){
    cin>>n>>m;
    inputGraph();
    cout<<bfs()<<endl;
}