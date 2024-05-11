#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int tree[N*3],arr[N];
int initi(int v){
    return v;
}
int merge(const int a,const int b){
    return a+b;
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
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,val);
    update((node<<1)+1,mid+1,e,i,val);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
int query(int node,int b,int e,int k){
    if(b==e) return b;
    int mid=(b+e)>>1;
    if(k<tree[node<<1]) return query(node<<1,b,mid,k);
    else return query((node<<1)+1,mid+1,e,k-tree[node<<1]);
}
int main(void){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    while(q--){
        int x,i;cin>>x>>i;
        if(x==1){
            arr[i]=1-arr[i];
            update(1,0,n-1,i,arr[i]);
        }else cout<<query(1,0,n-1,i)<<endl;
    }
}