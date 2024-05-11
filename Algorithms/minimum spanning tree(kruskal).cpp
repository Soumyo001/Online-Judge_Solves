#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int parent[N],sze[N];
void make(int i){
    parent[i]=i;
    sze[i]=1;
}
int find(int i){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i]);
}
int Union(int i,int j){
    int a=find(i);
    int b=find(j);
    if(a!=b){
        if(sze[a]<sze[b]) swap(a,b);
        parent[b]=a;
        sze[a]+=sze[b];
        return 0;
    }else return 1;
}
int main(void){
    int n,e,total_cost=0;cin>>n>>e;
    multiset<pair<int,pair<int,int>>>m;
    for(int i=0;i<e;i++){
        int wt,u,v;cin>>u>>v>>wt;
        m.insert(make_pair(wt,make_pair(u,v)));
    }
    for(int i=1;i<=n;i++) make(i);
    for(auto &x:m){
        int wt=x.first;
        int u=x.second.first;
        int v=x.second.second;
        //if(find(u)==find(v)) continue;
        if(Union(u,v)) continue;
        cout<<u<<" "<<v<<endl;
        total_cost+=wt;
    }
    cout<<total_cost<<endl;
}