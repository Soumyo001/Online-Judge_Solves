#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N];
struct Tree{
    unordered_set<int> s;
} tree[N*3];
void init(int node,int b,int e){
    if(b==e){
        tree[node].s.insert(arr[b]);
        return;
    }
    int mid=(b+e)>>1;
    init(node<<1,b,mid);
    init((node<<1)+1,mid+1,e);
    for(auto& i:tree[node<<1].s) tree[node].s.insert(i);
    for(auto& i:tree[(node<<1)+1].s) tree[node].s.insert(i);
}
unordered_set<int> query(int node,int b,int e,int i,int j){
    if(e<i || j<b) return {};
    if(b>=i && e<=j) return tree[node].s;
    int mid=(b+e)>>1;
    unordered_set<int> n=query(node<<1,b,mid,i,j);
    unordered_set<int> m=query((node<<1)+1,mid+1,e,i,j);
    for(auto& i:m) n.insert(i);
    return n;
}
int main(void){
    int t;cin>>t;
    for(int tst=1;tst<=t;tst++){
        cout<<"Case "<<tst<<": \n";
        string line;getline(cin,line);
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=1;i<=N*3;i++) tree[i].s.clear();
        init(1,1,n);
        while(q--){
            int a,b;cin>>a>>b;
            unordered_set<int> s=query(1,1,n,a,b);
            cout<<s.size()<<"\n";
        }
    }
}