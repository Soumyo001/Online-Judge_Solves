#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int tree[N*3],lazy[N*3],arr[N];
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
void update(int node,int b,int e,int i,int j,int x){
    if(lazy[node]!=-1){
        tree[node]=initi((e-b+1)*lazy[node]);
        if(b!=e){
            lazy[node<<1]=lazy[node];
            lazy[(node<<1)+1]=lazy[node];
        }lazy[node]=-1;
    }
    if(e<i || j<b) return;
    if(b>=i && e<=j){
        tree[node]=initi((e-b+1)*x);
        if(b!=e){
            lazy[node<<1]=x;
            lazy[(node<<1)+1]=x;
        }
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,j,x);
    update((node<<1)+1,mid+1,e,i,j,x);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
int query(int node,int b,int e,int i,int j){
    if(lazy[node]!=-1){
        tree[node]=initi((e-b+1)*lazy[node]);
        if(b!=e){
            lazy[node<<1]=lazy[node];
            lazy[(node<<1)+1]=lazy[node];
        }lazy[node]=-1;
    }
    if(e<i || j<b) return 0;
    if(b>=i && e<=j) return tree[node];
    int mid=(b+e)>>1;
    int n=query(node<<1,b,mid,i,j);
    int m=query((node<<1)+1,mid+1,e,i,j);
    return merge(n,m);
}
int main(void){
    memset(lazy,-1,sizeof(lazy));
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);
    while(true){
        int q;cin>>q;
        if(q==1){
            int l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }else if(q==2){
            int i,j,x;cin>>i>>j>>x;
            update(1,1,n,i,j,x);
        }else if(q==3){
            for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }else break;
    }
}
/*
8
3 5 7 1 0 4 6 12
1 1 4
16
2 1 4 4
1 1 4
16
2 1 4 5
1 1 4
20
2 3 4 4
1 1 4
18
2 3 3 5                                                
1 1 4
19
2 4 4 5
1 1 4
20
2 1 2 3
1 1 4
16
9*/