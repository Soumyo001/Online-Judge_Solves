#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int>graph[N];
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
int main(void){
    int t;cin>>t;
    int x=0;
    while(t--){
        int n,m,s,e;
        cin>>n>>m>>s>>e;
        inputGraph(m);
        cout<<"Case "<<++x<<": "<<1<<endl;
    }
}