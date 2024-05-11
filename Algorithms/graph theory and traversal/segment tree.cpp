#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N],tree[N*3];
int initi(int v){
    return v;
}
int merge(const int a,const int b){
    return a+b;
}
void init(int node,int s,int e){
    if(s==e){
        tree[node]=initi(arr[s]);
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    tree[node]=merge(tree[left],tree[right]);
}
void update(int node,int s,int e,int i,int newVal){
    if(i>e || i<s) return;
    if(s>=i && e<=i){
        tree[node]=initi(newVal);
        arr[s]=initi(newVal);
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    update(left,s,mid,i,newVal);
    update(right,mid+1,e,i,newVal);
    tree[node]=merge(tree[left],tree[right]);
}
int query(int node,int s,int e,int i,int j){
    if(i>e || j<s) return 0;
    if(s>=i && e<=j) return tree[node];
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    int n=query(left,s,mid,i,j);
    int m=query(right,mid+1,e,i,j);
    return merge(n,m);
}
int main(void){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    while(true){
        int a,b,c;cin>>a>>b>>c;
        if(a==1) update(1,0,n-1,b-1,c);
        else if(a==2) cout<<query(1,0,n-1,b-1,c-1)<<endl;
        else break;
    }
}