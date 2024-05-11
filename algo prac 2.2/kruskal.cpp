#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N],sze[N];
int n,m;
multiset<pair<int,pair<int,int>>> s;
void make(int i){
    parent[i]=i;
    sze[i]=1;
}
int find(int i){
    return (i == parent[i] ? i : parent[i]=find(parent[i]));
}
void Union(int i, int j){
    int a = find(i);
    int b = find(j);
    if(a != b){
        if(sze[a] < sze[b]) swap(a, b);
        parent[b] = a;
        sze[a] += sze[b];
    }
}
int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        s.insert({wt,{u,v}});
    }
    for(int i=1;i<=n;i++) make(i);
    int tot = 0, cnt = 0;
    for(auto& i:s){
        int u = i.second.first;
        int v = i.second.second;
        int wt = i.first;
        if(find(u) == find(v)) continue;
        Union(u,v);
        cout<<u<<" "<<v<<endl;
        tot += wt;
        cnt++;
    }
    cout<<cnt<<" "<<tot<<endl;
}