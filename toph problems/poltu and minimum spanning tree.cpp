#include<bits/stdc++.h>
using namespace std;
const int N=8e5+5;
int parent[N],sze[N];
int n,e,k;
struct Edge{
    int u,v,c;
    long long wt;
    Edge(int wt,int u,int v,int c){
        this->wt=wt;
        this->u=u;
        this->v=v;
        this->c=c;
    }
};
vector<Edge> edges;
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
int main(void){
    cin>>n>>e>>k;
    for(int i=1;i<=n;i++) make(i);
    for(int i=0;i<e;i++){
        int u,v,c;long long wt;cin>>u>>v>>wt>>c;
        edges.push_back(Edge(wt,u,v,c));
    }
    sort(edges.begin(),edges.end(),[](const Edge& a, const Edge& b){

        return a.wt<b.wt;
    });
    //for(auto& i:edges) cout<<i.wt<<" "<<i.u<<" "<<i.v<<" "<<i.c<<endl; 
    long long total_cost=0;int cnt=0;
    for(auto& i:edges){
        int u=i.u;
        int v=i.v;
        long long wt=i.wt;
        int c=i.c;
        if(find(u)!=find(v)){
            Union(u,v);
            //cout<<u<<" "<<v<<endl;
            total_cost+=wt;
            cnt+=c;
        }
    }
    cout<<cnt<<endl;
    if(cnt==k) cout<<total_cost<<endl;
    else cout<<-1<<endl;
}