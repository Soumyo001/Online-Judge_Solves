#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int sze[N],parent[N];
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
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) make(i);
    while(q--){
        int a,b,c;cin>>a>>b>>c;
        if(a==0) Union(b,c);
        else if(a==1){
            if(find(b)==find(c)) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}