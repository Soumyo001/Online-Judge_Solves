#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
vector<pair<int,long long>> graph[N];
long long mini=LLONG_MAX;
bool vis[N];
int n,q,tank,tap,indeg[N];
int u,v;long long wt;
struct ANSWER{
    int tank,tap;long long dm;
    ANSWER(int _tank,int _tap,long long _dm){
        tank=_tank;
        tap=_tap;
        dm=_dm;
    }
};
vector<ANSWER> ans;
void inputGraph(){
    for(int i=0;i<q;i++){
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        ++indeg[v];
        //graph[v].push_back({u,wt});
    }
}
bool dfs(int vertex,int par){
    vis[vertex]=true;
    int flag=1;
    bool isLoop=false;
    for(auto& i:graph[vertex]){
        if(vis[i.first] && i.first==par) continue;
        if(vis[i.first]) return true;
        isLoop |= dfs(i.first,vertex);
        flag=0;
        mini=min(mini,i.second);
    }
    if(flag) tap=vertex;
    return isLoop;
}
int main(void){
    cin>>n>>q;
    if(q==0){
        cout<<0<<endl;return 0;
    }
    inputGraph();
    if(q==1){
        cout<<1<<endl<<u<<" "<<v<<" "<<wt<<endl;return 0; 
    }
    int a=0;
    for(int i=1;i<=n;i++){
        if(!vis[i] && indeg[i]==0){
            //cout<<i<<endl;
            tank=i;
            mini=INT_MAX;
            if(dfs(i,-1)){
                cout<<0<<endl;return 0;
            }++a;
            ans.push_back({tank,tap,mini});
        }
    }
    sort(ans.begin(),ans.end(),[&](const ANSWER& a,const ANSWER &b){
        return a.tank<b.tank;
    });
    cout<<a<<endl;
    for(auto& i:ans) cout<<i.tank<<" "<<i.tap<<" "<<i.dm<<endl;
}