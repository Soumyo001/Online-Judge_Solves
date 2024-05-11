#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
int parent[N];
int n,m;
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par){
    parent[vertex]=par;
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
    }
}
vector<int> lca(int a){
    vector<int>v;
    while(a!=0){
        v.push_back(a);
        a=parent[a];
    }
    reverse(v.begin(),v.end());
    return v;
}
int main(void){
    cin>>n>>m;
    inputGraph();
    dfs(1,0);
    int q;cin>>q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> va = lca(a);
        vector<int> vb = lca(b);
        vector<int> vc = lca(c);
        int ansc = -1;
        for (int i = 0; i < min(va.size(), min(vb.size(), vc.size())); i++){
            if (va[i] == vb[i] && va[i] == vc[i] && vb[i] == vc[i]) ansc = va[i];
            else break;
        }
        cout << ansc << endl;
    }
}