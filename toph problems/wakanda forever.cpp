#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N],sze[N],arr[N];
multiset<pair<int,pair<int,int>>> edges;
void make(int i){
    parent[i]=i;
    sze[i]=1;
}
int find(int i){
    return parent[i]==i ? i:parent[i]=find(parent[i]);
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,d,c=0,k=0,sum=0;cin>>n>>m>>d;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]) c++;
        make(i);
    }
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        if(arr[u] && arr[v]) edges.insert({wt,{u,v}});
    }
    for(auto& i:edges){
        if(find(i.second.first)==find(i.second.second)) continue;
        Union(i.second.first,i.second.second);
        sum+=i.first;
        k++;
    }
    if(k<c-1) sum+=(c-1-k)*d;
    cout<<sum<<endl;
}