#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N],tree[N*3];
void init(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=(node<<1)+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[node];
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=(node<<1)+1;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
void update(int node,int b,int e,int i,int x){
    if(e<i || i<b) return;
    if(b>=i && e<=i) {
        tree[node]=x;
        arr[i]=x;
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=(node<<1)+1;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    tree[node]=tree[left]+tree[right];
}
int main(void){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    while(true){
        int q;cin>>q;
        if(q==1){
            int l,r;cin>>l>>r;
            cout<<query(1,0,n-1,--l,--r)<<endl;
        }else if(q==2){
            int i,x;cin>>i>>x;
            update(1,0,n-1,--i,x);
        }else break;
    }
}