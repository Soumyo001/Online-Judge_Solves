#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long arr[N];
struct Tree
{
    long long min=0;
    int freq=0;
} tree[N*3];
Tree merge(const Tree a,const Tree b){
    if(a.min<b.min) return a;
    if(a.min>b.min) return b;
    return {a.min,a.freq+b.freq};
}
Tree initi(int v){
    return {v,1};
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
void update(int node,int b,int e,int i,long long val){
    if(e<i || i<b) return;
    if(b>=i && e<=i){
        tree[node]=initi(val);
        arr[i]=val;
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,val);
    update((node<<1)+1,mid+1,e,i,val);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
Tree query(int node,int b,int e,int i,int j){
    if(e<i || j<b) return {LLONG_MAX,0};
    if(b>=i && e<=j) return tree[node];
    int mid=(b+e)>>1;
    Tree n=query(node<<1,b,mid,i,j);
    Tree m=query((node<<1)+1,mid+1,e,i,j);
    return merge(n,m);
}
int main(void){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    while(q--){
        int x;cin>>x;
        if(x==1) {int i;long long j;cin>>i>>j;update(1,0,n-1,i,j);}
        else {int i,j;cin>>i>>j;cout<<query(1,0,n-1,i,j-1).min<<" "<<query(1,0,n-1,i,j-1).freq<<endl;}
    }
}