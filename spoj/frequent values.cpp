#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N];
struct Node{
    unordered_map<int,int> m;
    pair<int,int> fr;
}tree[N*4];
pair<int,int> getMax(unordered_map<int,int>& a){
    pair<int,int> freq={0,0};
    for(auto& i:a){
        if(freq.second<i.second){
            freq.first=i.first;
            freq.second=i.second;
        }
    }
    return freq;    
}
pair<int,int> merge(pair<int,int>& a,pair<int,int>& b){
    if(a.first==b.first) return make_pair(a.first,a.second+b.second);
    return (a.second<b.second ? b:a);
}
void init(int node,int s,int e){
    if(s==e){
        tree[node].m[arr[s]]++;
        tree[node].fr.first=arr[s];
        tree[node].fr.second=1;
        return;
    }
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,s,mid);
    init(right,mid+1,e);
    for(auto& i:tree[left].m) tree[node].m[i.first]+=i.second;
    for(auto& i:tree[right].m) tree[node].m[i.first]+=i.second;
    for(auto& i:tree[node].m) cout<<i.first<<" "<<i.second<<endl;
    tree[node].fr=getMax(tree[node].m);
}
pair<int,int> query(int node,int s,int e,int i,int j){
    if(i>e || j<s) return {0,0};
    if(s>=i && e<=j) return tree[node].fr;
    int mid=(s+e)/2;
    int left=2*node;
    int right=2*node+1;
    pair<int,int> n=query(left,s,mid,i,j);
    pair<int,int> m=query(right,mid+1,e,i,j);
    return merge(n,m);
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int n,q;cin>>n>>q;
        if(n==0) break;
        for(int i=1;i<=n;i++) cin>>arr[i];
        init(1,1,n);
        while(q--){
            int i,j;cin>>i>>j;
            printf("%d\n",query(1,1,n,i,j).second);
        }
        for(int i=1;i<=N;i++){
            tree[i].m.clear();
            tree[i].fr.first=tree[i].fr.second=0;
        }
    }
}