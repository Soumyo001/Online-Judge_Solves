#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long arr[N];
struct info{
    long long max=0;
    multiset<pair<int,int>>m;
}tree[N*3];
void init(int node,int s,int e){
    if(s==e){
        tree[node].max=arr[s];
        tree[node].m.insert({arr[s],s});
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    tree[node].max=max(tree[left].max,tree[right].max);
    for(auto& i:tree[left].m) tree[node].m.insert({i.first,i.second});
    for(auto& i:tree[right].m) tree[node].m.insert({i.first,i.second});
}
void update(int node,int s,int e,int i,int newVal,int temp){
    if(i>e || i<s) return;
    if(s>=i && e<=i){
        tree[node].m.erase(tree[node].m.find({arr[s],s}));
        tree[node].m.insert({newVal,s});
        tree[node].max=newVal;
        arr[s]=newVal;
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    update(left,s,mid,i,newVal,temp);
    update(right,mid+1,e,i,newVal,temp);
    tree[node].m.erase(tree[node].m.find({temp,i}));
    tree[node].m.insert({newVal,i});
    tree[node].max=max(tree[left].max,tree[right].max);
}
long long query(int node,int s,int e,int i,int j){
    if(i>e || j<s) return LLONG_MIN;
    if(s>=i && e<=j) return tree[node].max;
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    long long n=query(left,s,mid,i,j);
    long long m=query(right,mid+1,e,i,j);
    return max(n,m);
}
int query1(int node,int s,int e,int Xi,int Vi,int range){
    if(Xi>e || s>range) return INT_MAX;
    if(s>=Xi && e<=range){
        for(auto& i:tree[node].m) if(i.first>=Vi) return i.second;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    int n=query1(left,s,mid,Xi,Vi,range);
    int m=query1(right,mid+1,e,Xi,Vi,range);
    return min(n,m);
}
int main(void){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);
    while(q--){
        int a,b,c;cin>>a>>b>>c;
        if(a==1) update(1,1,n,b,c,arr[b]);
        else if(a==2) cout<<query(1,1,n,b,c)<<endl;
        else if(a==3){
            int x=0;
            for(int i=b;i<=n;i++){
                if(arr[i]>=c){
                    x=i;break;
                }
            }
            cout<<(x==0 ? n+1:x)<<endl;
        }
    }
}

///Xi≤j≤N, Vi≤Aj