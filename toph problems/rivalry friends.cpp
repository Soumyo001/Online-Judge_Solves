#include<bits/stdc++.h>
using namespace std;
const int N=5e5+6;
vector<bool>isPrime(N,1);
int phi[N+5],arr[N],tree[N*5];
void sieve(){
    for(int i=1;i<=N;i++) phi[i]=i;
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=N;i++) if(isPrime[i]) for(int j=i*i;j<=N;j+=i) isPrime[j]=false;
    for(int i=1;i<=N;i++){
        if(isPrime[i]){
            for(int j=i;j<=N;j+=i) phi[j]-=(phi[j]/i);
        }
    }
}
void init(int node,int s,int e){
    if(s==e){
        tree[node]=phi[arr[s]];
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void update(int node,int s,int e,int i,int newVal){
    if(i>e || i<s) return;
    if(s==i && e==i){
        tree[node]=phi[newVal];
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    update(left,s,mid,i,newVal);
    update(right,mid+1,e,i,newVal);
    tree[node]=tree[left]+tree[right];
}
long long query(int node,int s,int e,int i,int j){
    if(i>e || j<s) return 0;
    if(s>=i && e<=j) return tree[node];
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    long long n=query(left,s,mid,i,j);
    long long m=query(right,mid+1,e,i,j);
    return (n+m);
}
int main(void){
    sieve();
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    while(q--){
        int a,b,c;cin>>a>>b>>c;
        if(a==1) update(1,0,n-1,b-1,c);
        else if(a==2) cout<<query(1,0,n-1,b-1,c-1)<<endl;
    }
}