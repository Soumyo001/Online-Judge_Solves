#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N],tree[N*3];
int initi(int v){
    return v;
}
int merge(const int a,const int b){
    return max(a,b);
}
void init(int node,int b,int e){
    if(b==e){
        tree[node]=initi(arr[b]);return;
    }
    int mid=(b+e)>>1;
    init(node<<1,b,mid);
    init((node<<1)+1,mid+1,e);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
void update(int node,int b,int e,int i,int x){
    if(e<i || i<b) return;
    if(b>=i && e<=i){
        tree[node]=initi(x);arr[b]=x;
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,x);
    update((node<<1)+1,mid+1,e,i,x);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
int query(int node,int b,int e,int x){
    if(x>tree[node]) return -1;
    if(b==e) return b;
    int mid=(b+e)>>1;
    int r=query(node<<1,b,mid,x);
    if(r==-1) r=query((node<<1)+1,mid+1,e,x);
    return r;
}
int main(void){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    while(q--){
        int i;cin>>i;
        if(i==1){
            int j,k;cin>>j>>k;
            update(1,0,n-1,j,k);
        }else{
            int x;cin>>x;
            cout<<query(1,0,n-1,x)<<endl;
        }
    }
}