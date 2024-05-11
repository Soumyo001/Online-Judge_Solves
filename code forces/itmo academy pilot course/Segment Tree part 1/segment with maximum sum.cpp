#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Tree{
    long long seg=0,pre=0,suf=0,sum=0;
}tree[N*3];
int arr[N];
Tree neutral_element={0,0,0,0};
Tree initi(int v){
    if(v>0) return {v,v,v,v};
    return {0,0,0,v};
}
Tree merge(const Tree a, const Tree b){
    return {
        max(a.seg,max(b.seg,a.suf+b.pre)),
        max(a.pre,a.sum+b.pre),
        max(b.suf,b.sum+a.suf),
        a.sum+b.sum
    };
}
void init(int node,int b,int e){
    if(b==e){
        tree[node]=initi(arr[b]);
        return;
    }
    int mid=(b+e)>>1;
    init(node<<1,b,mid);
    init((node<<1)+1,mid+1,e);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
void update(int node,int b,int e,int i,int val){
    if(e<i || i<b) return;
    if(b>=i && e<=i){
        tree[node]=initi(val);
        arr[i]=val;
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,val);
    update((node<<1)+1,mid+1,e,i,val);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
Tree query(int node,int b,int e,int i,int j){
    if(e<i || j<b) return neutral_element;
    if(b>=i && e<=j) return tree[node];
    int mid=(b+e)>>1;
    Tree n=query(node<<1,b,mid,i,j);
    Tree m=query((node<<1)+1,mid+1,e,i,j);
    return merge(n,m);
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
    cout<<query(1,0,n-1,0,n-1).seg<<endl;
    while(q--) {
        int i,j;
        cin>>i>>j;
        update(1,0,n-1,i,j);
        cout<<query(1,0,n-1,0,n-1).seg<<endl;
    }
}