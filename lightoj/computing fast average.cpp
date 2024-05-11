#include<bits/stdc++.h>
#include<stdexcept>
#define gcd(x,y) __gcd(x,y)
using namespace std;
const int N=1e5+5;
int arr[N];
int tree[N*3],lazy[N*3];
void update(int node,int b,int e,int i,int j,int v){
    if(lazy[node]!=-1){
        tree[node]=(e-b+1)*lazy[node];
        if(b!=e){
            lazy[node<<1]=lazy[node];
            lazy[(node<<1)+1]=lazy[node];
        }lazy[node]=-1;
    }
    if(e<i || j<b) return;
    if(b>=i && e<=j){
        tree[node]=(e-b+1)*v;
        if(b!=e){
            lazy[node<<1]=v;
            lazy[(node<<1)+1]=v;
        }
        return;
    }
    int mid=(b+e)>>1;
    update((node<<1),b,mid,i,j,v);
    update((node<<1)+1,mid+1,e,i,j,v);
    tree[node]=tree[(node<<1)]+tree[(node<<1)+1];
}
int query(int node,int b,int e,int i,int j){
    if(lazy[node]!=-1){
        tree[node]=(e-b+1)*lazy[node];
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
    return n+m;
}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": "<<endl;
        int n,q;cin>>n>>q;
        for(int i=0;i<=N*3;i++) tree[i]=0,lazy[i]=-1;
        while(q--){
            int v;cin>>v;
            if(v==1){
                int i,j,v;cin>>i>>j>>v;++i,++j;
                update(1,1,n,i,j,v);
            }else if(v==2){
                int i,j;cin>>i>>j;++i,++j;
                int h=query(1,1,n,i,j);
                int div=gcd(h,(j-i+1));
                int b=(j-i+1)/div;
                h/=div;
                if(b==1) cout<<h<<"\n";
                else cout<<h<<"/"<<b<<"\n";
            }
        }
    }
}