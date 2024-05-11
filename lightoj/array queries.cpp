#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N],tree[N*3];
void init(int node,int s,int e){
    if(s==e){
        tree[node]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
void update(int node,int s,int e,int i,int newVal){
    if(i>e || i<s) return;
    if(s>=i && e<=i){
        tree[node]=newVal;
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    update(left,s,mid,i,newVal);
    update(right,mid+1,e,i,newVal);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int s,int e,int i,int j){
    if(i>e || j<s) return INT_MAX;
    if(s>=i && e<=j) return tree[node];
    int mid=(s+e)/2;
    int left=node*2;
    int right=node*2+1;
    int n=query(left,s,mid,i,j);
    int m=query(right,mid+1,e,i,j);
    return min(n,m);
}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>arr[i];
        init(1,1,n);
        cout<<"Case "<<i<<":"<<endl;
        while(q--){
            int i,j;cin>>i>>j;
            cout<<query(1,1,n,i,j)<<endl;
        }
        for(int i=0;i<=N;i++) tree[i]=0;
    }
}