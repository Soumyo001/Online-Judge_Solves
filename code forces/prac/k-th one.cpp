#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N],tree[N*3];
void init(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];return;
    }
    int mid=(b+e)/2;
    init(node<<1,b,mid);
    init((node<<1)+1,mid+1,e);
    tree[node]=tree[node<<1]+tree[(node<<1)+1];
}
void update(int node,int b,int e,int i,int x){
    if(e<i || i<b) return;
    if(b>=i && e<=i){
        tree[node]=x;return;
    }
    int mid=(b+e)/2;
    update(node<<1,b,mid,i,x);
    update((node<<1)+1,mid+1,e,i,x);
    tree[node]=tree[node<<1]+tree[(node<<1)+1];
}
int query(int node,int b,int e,int k){
    if(b==e) return b;
    int mid=(b+e)/2;
    if(k<tree[node<<1]) return query(node<<1,b,mid,k);
    else return query((node<<1)+1,mid+1,e,k-tree[node<<1]);
}
int main(void){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    while(q--){
        int x,k;cin>>x>>k;
        if(x==1){
            arr[k]=1-arr[k];
            update(1,0,n-1,k,arr[k]);
        }else cout<<query(1,0,n-1,k)<<endl;
    }
}