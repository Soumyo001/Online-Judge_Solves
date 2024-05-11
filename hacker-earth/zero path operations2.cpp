#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int parent[N];
int sze[N];
void make(int i){
    parent[i]=i;
    //sze[i]=1;
}
int find(int i){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i]);
}
void Union(int i,int j){
    int a=find(i);
    int b=find(j);
    if(a!=b){
        if(sze[i]<sze[j]) swap(i,j);
        parent[j]=i;
        sze[i]++;
        sze[j]++;
    }
}
void reset(int n){
    for(int i=1;i<=n;i++){sze[i]=0;parent[i]=0;}
}
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        reset(n);
        for(int i=1;i<=n;i++) make(i);
        int e=n-1;
        while(e--){
            int a,b;cin>>a>>b;
            Union(a,b);
        }
        ll a[n+1];
        for(int i=1;i<=n;i++) cin>>a[i];
        int ct=0;
        for(int i=1;i<=n;i++) if(sze[i]>=2 && a[i]) ct++;
        cout<<ct<<endl;
    }
}