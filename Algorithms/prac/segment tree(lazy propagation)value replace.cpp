#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int tree[N*3],lazy[N*3],arr[N];
int initi(int a){
    return a;
}
int merge(int a,int b){
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
void update(int node,int b,int e,int i, int j,int val){
    if(lazy[node]!=-1){
        tree[node]=initi((e-b+1)*lazy[node]);
        if(b!=e){
            lazy[node<<1]=lazy[node];
            lazy[(node<<1)+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(i>e || j<b) return;
    if(b>=i && e<=j){
        tree[node]=initi((e-b+1)*val);
        if(b!=e){
            lazy[node<<1]=val;
            lazy[(node<<1)+1]=val;
        }
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,j,val);
    update((node<<1)+1,mid+1,e,i,j,val);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
int query(int node,int b,int e,int i,int j){
    if(lazy[node]!=-1){
        tree[node]=initi((e-b+1)*lazy[node]);
        if(b!=e){
            lazy[node<<1]=lazy[node];
            lazy[(node<<1)+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(i>e || b>j) return 0;
    if(b>=i && e<=j) return tree[node];
    int mid=(b+e)>>1;
    int n=query(node<<1,b,mid,i,j);
    int m=query((node<<1)+1,mid+1,e,i,j);
    return merge(n,m);
}
int main(void){
    memset(lazy,-1,sizeof(lazy));
    int n;cin>>n;
    for(int i=1;i<=n;++i) cin>>arr[i];
    init(1,1,n);
    while(true){
        int x;cin>>x;
        if(x==1){
            int i,j;cin>>i>>j;
            cout<<query(1,1,n,i,j)<<'\n';
        }else if(x==2){
            int i,j,k;cin>>i>>j>>k;
            update(1,1,n,i,j,k);
        }else break;
    }
}