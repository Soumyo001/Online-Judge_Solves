#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> graph[N];
int fsize[N],farray[N];
int parent[N];
int n,q,ct=0;
void inputGraph(){
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int source,int par,int k){
    farray[source]=(fsize[source]<k)?1:0;
    for(auto& i:graph[source]){
        if(i==par) continue;
        dfs(i,source,k);
        if(k>fsize[i]) farray[source]+=farray[i];
        //if(fsize[source]>=k) farray[source]--;
    }
    //cout<<farray[source]<<" "<<source<<endl;
}
void dfs1(int source,int par){
    parent[source]=par;
    for(auto& i:graph[source]){
        if(i==par) continue;
        dfs1(i,source);
    }
}
int main(void){
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>fsize[i];
    inputGraph();
    //dfs1(0,-1);
    while(q--){
        ct=0;
        int a,b;cin>>a>>b;
        dfs(0,-1,b);
        cout<<farray[a]<<endl;
    }
}
