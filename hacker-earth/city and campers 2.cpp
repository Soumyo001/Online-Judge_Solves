#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N],sze[N];
vector<int>m;
void make(int i){
    parent[i]=i;
    sze[i]=1;
    m.push_back(1);
}
int find(int i){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i]);
}
void Union(int i,int j){
    int a=find(i);
    int b=find(j);
    if(a!=b){
        if(sze[a]<sze[b]) swap(a,b);
        parent[b]=a;
        m.erase(find(m.begin(),m.end(),sze[a]));
        m.erase(find(m.begin(),m.end(),sze[b]));
        sze[a]+=sze[b];
        m.push_back(sze[a]);
    }
}
int main(void){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) make(i);
    while(q--){
        int a,b;cin>>a>>b;
        Union(a,b);
        if(m.size()==1){
            cout<<0<<endl;return 0;
        }
        sort(m.begin(),m.end());
        int mindiff=m[1]-m[0];
        int mx=m[0];
        for(int i=1;i<m.size();i++){
            mindiff=abs(min(mindiff,m[i]-mx));
            mx=max(m[i],mx);
        }
        cout<<mindiff<<endl;
    }
}