#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
vector<int> graph[N];
int state[N],n,q;
void inputGraph(){
    for(int i=1;i<=n;i++) graph[i].clear();
    for(int i=1;i<=(n-1);i++){
        int u,v;cin>>u>>v;
        graph[min(u,v)].push_back(max(u,v));
    }
}
void dfs(int vertex,int par){
    //cout<<vertex<<" "<<state[vertex]<<endl;
    state[vertex]=(state[vertex]==1 ? 0:1);
    //cout<<vertex<<" "<<state[vertex]<<endl;
    for(auto& i:graph[vertex]) if(i!=par) dfs(i,vertex);
}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>state[i];
        inputGraph();
        while(q--){
            int x;cin>>x;
            dfs(x,-1);
        }
        cout<<"Case "<<i<<": ";
        for(int i=1;i<=n;i++) cout<<state[i]<<" ";
        cout<<endl;
    }
}