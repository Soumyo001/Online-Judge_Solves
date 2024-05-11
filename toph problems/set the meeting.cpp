#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
int status[N];
int n,m;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void initiStatus(){
    for(int i=1;i<=n;i++) status[i]=1;
}
vector<int> bfs(int source){
    initiStatus();
    vector<int>level(n+1,0);
    queue<int>q;
    q.push(source);
    status[source]=2;
    while(!q.empty()){
        int val=q.front();q.pop();
        status[val]=3;
        for(const auto& i:graph[val]){
            if(status[i]==1){
                q.push(i);
                status[i]=2;
                level[i]=level[val]+1;
            }
        }
    }
    return level;
}
int main(void){
    cin>>n>>m;
    inputGraph();
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>la=bfs(a);
    vector<int>lb=bfs(b);
    vector<int>lc=bfs(c);
    long long min=LLONG_MAX;
    int p=0;
    for(int i=1;i<=n;i++){
        if(la[i]+lb[i]+lc[i]<min) min=la[i]+lb[i]+lc[i],p=i;
    }
    cout<<p<<endl;
}