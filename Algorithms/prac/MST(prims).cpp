#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>>graph[N];
int parent[N],sze[N];
int n,m,s;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
}
void make(int i){
    parent[i]=i;
    sze[i]=1;
}
int find(int i){
    return (parent[i]==i ? i:parent[i]=find(parent[i]));
}
void Union(int i,int j){
    int a=find(i);
    int b=find(j);
    if(a!=b){
        if(sze[a]<sze[b]) swap(a,b);
        parent[b]=a;
        sze[a]+=sze[b];
    }
}
int MST(int source){
    multiset<pair<int,pair<int,int>>> st;
    int cost=0;
    for(auto& i:graph[source]) st.insert({i.second,{source,i.first}});
    while(!st.empty()){
        int wt=st.begin()->first;
        int u=st.begin()->second.first;
        int v=st.begin()->second.second;
        st.erase(st.begin());
        if(find(u)!=find(v)){
            Union(u,v);
            cost+=wt;
            for(auto& i:graph[v]) st.insert({i.second,{v,i.first}});
        }
    }
    return cost;
}
int main(void){
    cin>>n>>m>>s;
    inputGraph();
    for(int i=1;i<=n;i++) make(i);
    cout<<MST(s)<<endl;
}