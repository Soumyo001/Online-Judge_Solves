#include<bits/stdc++.h>
using namespace  std;
const int N=1e5+5;
int parent[N],sze[N];
multiset<pair<int,pair<int,int>>> m;
int n,e;
void make(int i){
    parent[i]=i;
    sze[i]=1;
}
int find(int i){
    return i==parent[i] ? i:parent[i]=find(parent[i]);
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
int main(void){
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v,wt;cin>>u>>v>>wt;
        m.insert({wt,{u,v}});
    }
    for(int i=1;i<=n;i++) make(i);
    int cnt=0,totalCost=0;
    for(auto& i:m){
        int wt=i.first;
        int u=i.second.first;
        int v=i.second.second;
        if(find(u)!=find(v)){
            Union(u,v);
            cout<<u<<" "<<v<<endl;
            cnt++;totalCost+=wt;
        }
    }
    cout<<cnt<<" "<<totalCost<<endl;
}