#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
int arr[N];
pair<int,int> tree[3*N];
pair<int,int> Max(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        a.second+=b.second;
        return a;
    }
    if(a.first>b.first) return a;
    else return b;
}
void init(int node,int s,int e){
    if(s==e){
        tree[node].first=arr[s];
        tree[node].second=1;
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    tree[node]=Max(tree[left],tree[right]);
}
pair<int,int> query(int node,int s,int e,int i,int j){
    if(i>e || j<s) return {0,0};
    if(s>=i && e<=j) return tree[node];
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    pair<int,int> n=query(left,s,mid,i,j);
    pair<int,int> m=query(right,mid+1,e,i,j);
    return Max(n,m);
}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n,q;cin>>n>>q;
        for(int i=0;i<n;i++) cin>>arr[i];
        init(1,0,n-1);
        //for(int i=1;i<=10;i++)cout<<tree[i].first<<" ";
        cout<<"Case "<<i<<":"<<endl;
        while(q--){
            int i,j;cin>>i>>j;
            cout<<query(1,0,n-1,i,j).second<<endl;
        }
        for(int i=1;i<=3*n;i++) tree[i].first=tree[i].second=0;
    }
}