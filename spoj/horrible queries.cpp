#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct info{
    long long sum=0,prop=0;
}tree[N*3];
void update(int node,int s,int e,int i,int j,int x){
    if(i>e || j<s) return;
    if(s>=i && e<=j){
        tree[node].sum+=(e-s+1)*x;
        tree[node].prop+=x;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(s+e)/2;
    update(left,s,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-s+1)*tree[node].prop;
}
long long query(int node,int s,int e,int i,int j,long long carry=0){
    if(i>e || j<s) return 0;
    if(s>=i && e<=j) return tree[node].sum+(e-s+1)*carry;
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    long long n=query(left,s,mid,i,j,carry+tree[node].prop);
    long long m=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return (n+m);
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": "<<endl;
        int n,q;cin>>n>>q;
        while(q--){
            int a;cin>>a;
            if(a==0){
                int i,j,v;cin>>i>>j>>v;
                update(1,1,n,i,j,v);
            }else if(a==1){
                int a,b;cin>>a>>b;
                cout<<query(1,1,n,a,b)<<endl;
            }
        }
        for(int i=0;i<=3*N;i++) tree[i].sum=tree[i].prop=0;
    }
}