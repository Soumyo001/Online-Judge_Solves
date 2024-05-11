#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
int a[N],r=0;
int n,m;
void inputGraph(){
    for(int i=1;i<=(n-1);i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par,int c=0){
    if(a[vertex]==1 && a[par]==1) {
        c+=1;
        //cout<<c<<" "<<vertex<<" "<<par<<endl;
    }else c=0;
    if(c==m) {
        c=0;
        //c-=1;
        return;
    }
    int flag=1;
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        flag=0;
        dfs(i,vertex,c);
    }
    if(flag) {
        r++;
        //cout<<vertex<<endl;
    }
}
int main(void){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    inputGraph();
    //if(a[1]==1)a[0]=1;
    dfs(1,0);
    cout<<r<<endl;
}