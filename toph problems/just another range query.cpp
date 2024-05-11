#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll sum[35*N],prop[35*N];
int arr[35*N];
void init(int node,int s,int e){
    if(s==e){
        sum[node]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    sum[node]=sum[left]+sum[right];
}
void update(int node,int s,int e,int i,int j,int v){
    if(i>e || j<s) return;
    if(s>=i && e<=j){
        sum[node]-=(e-s+1)*v;
        prop[node]+=v;
        return;
    }
    int mid=(s+e)/2;
    update(2*node,s,mid,i,j,v);
    update(2*node+1,mid+1,e,i,j,v);
    sum[node]=sum[2*node]+sum[2*node+1]-(e-s+1)*prop[node];
}
long long  query(int node,int s,int e,int i,int j,int carry=0){
    if(i>e || j<s) return 0;
    if(s>=i && e<=j) return (sum[node]-(e-s+1)*carry);
    int mid=(s+e)/2;
    ll n=query(2*node,s,mid,i,j,carry+prop[node]);
    ll m=query(2*node+1,mid+1,e,i,j,carry+prop[node]);
    return (n+m);
}
int main(void){
    long long n,q;cin>>n>>q;
    for(long long i=1;i<=n;i++) arr[i]=i;
    init(1,1,n);
    while(q--){
        int a;cin>>a;
        if(a==1){
            ll l,r,v;cin>>l>>r>>v;
            update(1,1,n,l,r,v);
        }
        else if(a==2){
            ll l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
}