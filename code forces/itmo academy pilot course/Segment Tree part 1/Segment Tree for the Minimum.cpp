#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long tree[N*3],arr[N];
void init(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];return;
    }
    int mid=(b+e)>>1;
    init(node<<1,b,mid);
    init((node<<1)+1,mid+1,e);
    tree[node]=min(tree[node<<1],tree[(node<<1)+1]);
}
void update(int node,int b,int e,int i,long long val){
    if(e<i || i<b) return;
    if(b>=i && e<=i){
        tree[node]=val;
        arr[i]=val;
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,val);
    update((node<<1)+1,mid+1,e,i,val);
    tree[node]=min(tree[node<<1],tree[(node<<1)+1]);
}
long long query(int node,int b,int e,int i,int j){
    if(e<i || j<b) return LLONG_MAX;
    if(b>=i && e<=j) return tree[node];
    int mid=(b+e)>>1;
    long long n=query(node<<1,b,mid,i,j);
    long long m=query((node<<1)+1,mid+1,e,i,j);
    return min(n,m);
}
int main(void){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    while(q--){
        int x;cin>>x;
        if(x==1) {int i;long long j;cin>>i>>j;update(1,0,n-1,i,j);}
        else {int i,j;cin>>i>>j;cout<<query(1,0,n-1,i,j-1)<<endl;}
    }
}