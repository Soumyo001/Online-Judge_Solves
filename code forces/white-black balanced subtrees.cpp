#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>graph[N];
int n,a[N],b[N],w[N];
bool vis[N];
string color;
int st=0;
void inputGraph(){
    for(int i=0;i<=n;i++) graph[i].clear(),vis[i]=false,b[i]=w[i]=0;
    for(int i=2;i<=n;i++){
        graph[a[i]].push_back(i);
        graph[i].push_back(a[i]);
    }st=0;
}
void dfs(int vertex,int par){
    if(color[vertex-1]=='B') b[vertex]=1;
    else if(color[vertex-1]=='W') w[vertex]=1;
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
        b[vertex]+=b[i];
        w[vertex]+=w[i];
    }
    if(b[vertex]==w[vertex]) st++;
}
void solve(){
    cin>>n;
    for(int i=2;i<=n;i++) cin>>a[i];
    cin>>color;
    inputGraph();
    dfs(1,0);
    cout<<st<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
