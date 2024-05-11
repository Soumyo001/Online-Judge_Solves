#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int tree[N*3],arr[N];
int initi(int v){
    return v;
}
int merge(const int a,const int b){
    return max(a,b);
}
void init(int node,int b,int e){
    if(b==e){
        tree[node]=initi(arr[b]);
        return;
    }
    int mid=(b+e)>>1;
    init(node<<1,b,mid);
    init((node<<1)+1,mid+1,e);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
void update(int node,int b,int e,int i,int val){
    if(e<i || i<b) return;
    if(b>=i && e<=i){
        tree[node]=initi(val);
        arr[b]=initi(val);
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,val);
    update((node<<1)+1,mid+1,e,i,val);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
int query(int node,int b,int e,int l,int x){
    if(e<l) return -1;
    if(tree[node]<x) return -1;
    if(b==e) return b;
    int mid=(b+e)>>1;
    int res=query(node<<1,b,mid,l,x);
    if(res==-1) res=query((node<<1)+1,mid+1,e,l,x);
    return res;
}
int main(void){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    while(q--){
        int x,i,j;cin>>x>>i>>j;
        if(x==1) update(1,0,n-1,i,j);
        else cout<<query(1,0,n-1,j,i)<<endl;
    }
}