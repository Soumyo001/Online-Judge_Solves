#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>>m[N];
int parent[N],sze[N];
bool visited[N];
int n,e,s;
void make(int i){
    parent[i]=i;
    sze[i]=1;
}
int find(int i){
    return (i==parent[i] ? i:parent[i]=find(parent[i]));
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
    int total_cost=0;
    multiset<pair<int,pair<int,int>>> s;
    for(auto& i:m[source]){
        s.insert({i.second,{source,i.first}});
    }
    while(!s.empty()){
        int u=s.begin()->second.first;
        int v=s.begin()->second.second;
        int wt=s.begin()->first;
        //cout<<wt<<" "<<u<<" "<<v<<endl;
        s.erase(s.begin());
        if(find(u)!=find(v)){
            //cout<<"Combined :"<<wt<<" "<<u<<" "<<v<<endl;
            Union(u,v);
            total_cost+=wt;
            for(auto& i:m[v]) s.insert({i.second,{v,i.first}});
        }
    }
    return total_cost;
}
int main(void){
    cin>>n>>e>>s;
    for(int i=0;i<e;i++){
        int u,v,wt;cin>>u>>v>>wt;
        m[u].push_back({v,wt});
        m[v].push_back({u,wt});
    }
    for(int i=1;i<=n;i++) make(i);
    cout<<MST(s);
}