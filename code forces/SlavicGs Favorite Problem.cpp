#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int x=0;
vector<pair<int,int>> graph[N];
set<int> s;
queue<pair<int,int>> q;
int n,a,b;
void inputGraph(){
    x=0;
    s.clear();
    for(int i=0;i<=n;i++) graph[i].clear();
    for(int i=1;i<=(n-1);i++){
        int u,v, wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
}
void bfs1(int source){
    q.push({source,0});
    s.insert(x);
    while(!q.empty()){
        int v=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto& i:graph[v]){
            if(i.first==par || i.first==b) continue;
            q.push({i.first,v});
            x^=i.second;
            s.insert(x);
        }
    }
}
bool bfs2(int source){
    x=0;
    q.push({source,0});
    while(!q.empty()){
        int v=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto& i:graph[v]){
            if(i.first==par || i.first==b) continue;
            q.push({i.first,v});
            x^=i.second;
            if(s.count(x)) return true;
        }
    }
    return false;
}
void solve(){
        cin>>n>>a>>b;
        inputGraph();
        bfs1(a);
        if(bfs2(b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}
int main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}