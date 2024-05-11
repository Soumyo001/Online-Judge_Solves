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
    tree[node]=tree[left]+tree[right];
}
int query(int node,int s,int e,int i,int j){
    if(i>e || j<s) return 0;
    if(s>=i && e<=j) return tree[node];
    int mid=(s+e)/2;
    int left=node*2;
    int right=2*node+1;
    int n=query(left,s,mid,i,j);
    int m=query(right,mid+1,e,i,j);
    return n+m;
}
void update(int node,int s,int e,int i,int newVal){
    if(i>e || i<s) return;
    if(s>=i && e<=i){
        tree[node]+=newVal;
        return;
    }
    int mid=(s+e)/2;
    int left=node*2;
    int right=2*node+1;
    update(left,s,mid,i,newVal);
    update(right,mid+1,e,i,newVal);
    tree[node]=tree[left]+tree[right];
}
void update1(int node,int s,int e,int i){
    if(i>e || i<s) return;
    if(s>=i && e<=i){
        tree[node]=0;
        return;
    }
    int mid=(s+e)/2;
    int left=node*2;
    int right=node*2+1;
    update1(left,s,mid,i);
    update1(right,mid+1,e,i);
    tree[node]=tree[left]+tree[right];
}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n,q;cin>>n>>q;
        for(int i=0;i<n;i++) cin>>arr[i];
        init(1,0,n-1);
        cout<<"Case "<<i<<":"<<endl;
        while(q--){
            int a;cin>>a;
            if(a==1){
                int x;cin>>x;
                cout<<arr[x]<<endl;
                arr[x]=0;
                update1(1,0,n-1,x);
            }else if(a==2){
                int a,b;cin>>a>>b;
                arr[a]+=b;
                update(1,0,n-1,a,b);
            }else{
                int i,j;cin>>i>>j;
                cout<<query(1,0,n-1,i,j)<<endl;
            }
        }
        for(int i=0;i<=N;i++) tree[i]=0;
    }
}