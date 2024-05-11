#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long arr[N];
struct info{
    unordered_multiset<long long> s;
}tree[N*3];
void init(int node,int s,int e){
    if(s==e){
        //tree[node].val=arr[e];
        tree[node].s.insert(arr[e]);
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    //tree[node].val=tree[left].val+tree[right].val;
    for(auto& i:tree[left].s) tree[node].s.insert(i);
    for(auto& i:tree[right].s) tree[node].s.insert(i);
}
bool query(int node,int s,int e,int i,int j,int v){
    if(i>e || j<s) return false;
    if(s>=i && e<=j) return tree[node].s.find(v)!=tree[node].s.end();
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    bool n=query(left,s,mid,i,j,v);
    bool m=query(right,mid+1,e,i,j,v);
    return n | m;
}
int main(void){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);
    while(q--){
        int l,r;long long v;cin>>l>>r>>v;
        if(query(1,1,n,l,r,v)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}