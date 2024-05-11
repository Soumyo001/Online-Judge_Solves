#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int N1=1e7+7;
int arr[N],tree[N*3];
vector<bool> isPrime(N1,1);
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<N1;i++){
        if(isPrime[i]){
            for(int j=i*2;j<N1;j+=i) isPrime[j]=false;
        }
    }
}
void init(int node,int s,int e){
    if(s==e){
        tree[node]=(isPrime[arr[s]] ? 1:0);
        return;
    }
    int mid=(s+e)/2;
    int left=node*2;
    int right=node*2+1;
    init(left,s,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int s,int e,int i,int j){
    if(e<i || j<s) return 0;
    if(s>=i && e<=j) return tree[node];
    int mid=(s+e)/2;
    int left=node*2;
    int right=node*2+1;
    int n=query(left,s,mid,i,j);
    int m=query(right,mid+1,e,i,j);
    return n+m;
}
void update(int node,int s,int e,int i,int newVal){
    if(i>e || i<s) return;
    if(s>=i && e<=i){
        tree[node]=(isPrime[newVal] ? 1:0);
        return;
    }
    int mid=(s+e)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,s,mid,i,newVal);
    update(right,mid+1,e,i,newVal);
    tree[node]=tree[left]+tree[right];
}
int main(void){
    sieve();
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        if(x==1){
            int i,j;cin>>i>>j;
            cout<<query(1,1,n,i,j)<<endl;
        }else{
            int i,newVal;cin>>i>>newVal;
            update(1,1,n,i,newVal);
        }
    }
}