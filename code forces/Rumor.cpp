#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
bool vis[N];
int c[N],n,m;
void inputGraph(){
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}
int dfs(int vertex){
    vis[vertex]=true;
    int mn=INT_MAX;
    mn=min(mn,c[vertex]);
   // cout<<vertex<<" "<<c[vertex]<<" "<<mn<<endl;
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        mn=min(mn,dfs(i));
    }
    return mn;
}
int main(void){
    cin>>n>>m;
    inputGraph();
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i] && !graph[i].empty()) ans+=dfs(i);
        else if(!vis[i] && graph[i].empty())ans+=c[i];
    }
    cout<<ans<<endl;
}