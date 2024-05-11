#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int arr[N];
struct info{
    long long sum=0,val=0;
}tree[3*N];
int Min(int n,int m){
    if(n!=0 && m!=0) return min(n,m);
    if(n!=0 && m==0) return n;
    return m;
}
void init(int node,int s,int e){
    if(s==e){
        tree[node].val=arr[s];
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    tree[node].val=Min(tree[left].val,tree[right].val);
    tree[node].sum=tree[left].val+tree[right].val;
}
ll query(int node,int s,int e,int i,int j){
    if(i>e || j<s) return 1LL*0;
    if(s>=i && e<=j) return tree[node].val*(e-s+1);
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    ll n=query(left,s,mid,i,j);
    ll m=query(right,mid+1,e,i,j);
    return n+m;
}
int main(void){
    int n;cin>>n;
    for(int i=1;i<=n;i++) {cin>>arr[i];arr[i]=(arr[i]==-1 ?0:arr[i]);}
    init(1,1,n);
    int q;cin>>q;
    while(q--){
        int s,e;cin>>s>>e;
        cout<<query(1,1,n,s,e)<<endl;
    }
}