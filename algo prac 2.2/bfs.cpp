#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> graph[N];
int n,m,s,status[N];
int dist[N];
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void bfs(){
    for(int i=1;i<=n;i++) status[i]=1;
    queue<int> q;
    q.push(s);
    status[s]=2;
    while (!q.empty())
    {
        int v=q.front();q.pop();
        cout<<v<<" ";
        status[v]=3;
        for(auto& i:graph[v]){
            if(status[i]==1){
                q.push(i);
                status[i]=2;
                dist[i]=dist[v]+1;
            }
        }
    }
    cout<<endl;
}
void showLevel(){
    for(int i=1;i<=n;i++) cout<<"Level of "<<i<<" is "<<dist[i]<<endl;
}
int main(void){
    cin>>n>>m>>s;
    inputGraph();
    bfs();
    showLevel();
}
