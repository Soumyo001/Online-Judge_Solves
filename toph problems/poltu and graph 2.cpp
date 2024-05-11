#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int parent[N],sze[N];
int n,m;
struct st{
    int u,v;long long x;
    st(int u,int v,long long x){
        this->u=u;
        this->v=v;
        this->x=x;
    }
};
vector<st>edge,query;
void make(int i){
    parent[i]=i;
    sze[i]=1;
}
int find(int i){
    return i==parent[i]? i:parent[i]=find(parent[i]);
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
   cin>>n>>m;
   for(int i=1;i<=n;i++) make(i);
   for(int i=1;i<=m;i++){
    int u,v,wt;cin>>u>>v>>wt;
    edge.emplace_back(st(u,v,1LL*wt));
   }
   int q;cin>>q;
   for(int i=1;i<=q;i++){
    int s,x;
    cin>>s>>x;
    query.emplace_back(st(s,x,i));
   }
   sort(edge.begin(),edge.end(),[](const st& a,const st& b){
    return a.x<b.x;
   });
   sort(query.begin(),query.end(),[](const st& a,const st& b){
    return a.v<b.v;
   });
   vector<int>ans(q+1,0);
   int idx=0;
   for(int i=1;i<=q;i++){
    for(idx;idx<edge.size() && edge[idx].x<=query[i-1].v;idx++){
        Union(edge[idx].u,edge[idx].v);
    }
    ans[query[i-1].x]=sze[find(query[i-1].u)];
   }
   for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}