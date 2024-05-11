#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=1e5+5;
const int sN=1e8+1;
vector<bool> isPrime(sN,1);
struct info{
    long long max,min;
}tree[3*N];
vector<int> v;
long long arr[N];
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=4;i<N;i+=2) isPrime[i]=false;
    for(int i=3;(long long)i*i<N;i+=2) if(isPrime[i]) for(int j=(long long)i*i;j<N;j+=(i*2)) isPrime[j]=false;
    v.push_back(2);
    for(int i=3;i<N;i+=2) if(isPrime[i]) v.push_back(i);
}
void init(int node,int s,int e){
    if(s==e){
        tree[node].max=tree[node].min=arr[s];
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    tree[node].max=max(tree[left].max,tree[right].max);
    tree[node].min=min(tree[left].min,tree[right].min);
}
void update(int node,int s,int e,int i,int newVal){
    if(i>e || i<s) return;
    if(s>=i && e<=i){
        tree[node].max=tree[node].min=newVal;
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    update(left,s,mid,i,newVal);
    update(right,mid+1,e,i,newVal);
    tree[node].max=max(tree[left].max,tree[right].max);
    tree[node].min=min(tree[left].min,tree[right].min);
}
int primeCount(int s,int e){
    int S=s/100,E=e/100;
    int res=0;
    if(S==E){
        for(int i=s;i<=e;i++) res+=isPrime[i];
        return res;
    }
    return 0;
}
pair<int,int> query(int node,int s,int e,int i,int j){
    if(i>e || j<s) return make_pair(INT_MAX,INT_MIN);
    if(s>=i && e<=j) return make_pair(tree[node].min,tree[node].max);
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    auto n=query(left,s,mid,i,j);
    auto m=query(right,mid+1,e,i,j);
    return make_pair(min(n.first,m.first),max(n.second,m.second));
}
int main(void){
	ios_base::sync_with_stdio(false);cin.tie(0);
    sieve();
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);
    while(q--){
        int a,l,r;
        cin>>a>>l>>r;
        if(a==1) {update(1,1,n,l,r);arr[l]=r;}
        else if(a==2) {
            auto p=query(1,1,n,l,r);
            pair<int,int> x;
            //cout<<p.first<<" "<<p.second<<endl;
            x.first=upper_bound(v.begin(),v.end(),p.second)-v.begin();
            x.second=upper_bound(v.begin(),v.end(),p.first-1)-v.begin();
            cout<<x.first-x.second<<endl;
        }
    }
}