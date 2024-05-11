#include<bits/stdc++.h>
using namespace std;
const int N=200010;
multiset<pair<long long,pair<int,int>>> edges;
int parent[N],sze[N];
int n,m;
struct QUERY{
    int s;
    long long x;
    int id;
    QUERY(int s,long long x,int id){
        this->x=x;
        this->s=s;
        this->id=id;
    }
};
vector<QUERY> query;
void make(int i){
    parent[i]=i;
    sze[i]=1;
}
int find(int i){
    return parent[i]==i? i:parent[i]=find(parent[i]);
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
void inputGraph(){
    for(int i=1;i<=m;i++){
        int u,v;long long wt;cin>>u>>v>>wt;
        edges.insert({wt,{u,v}});
    }
}
bool cmp(const QUERY& a,const QUERY& b){
    return a.x<b.x;
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) make(i);
    inputGraph();
    int q;cin>>q;
    vector<int> ans(q+1,0);
    for(int i=1;i<=q;i++){
        int s;long long x;cin>>s>>x;
        QUERY q(s,x,i);
        query.push_back(q);
    }
    sort(query.begin(),query.end(),cmp);
    //for(auto& i:query) cout<<i.s<<" "<<i.x<<" "<<i.id<<endl;
    for(int j=1;j<=q;j++){
        while(!edges.empty() && edges.begin()->first<=query[j-1].x){
            Union(edges.begin()->second.first,edges.begin()->second.second);
            edges.erase(edges.begin());
        }
        ans[query[j-1].id]=sze[find(query[j-1].s)];
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}