#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N],lazy[N*3];
struct Tree{
    int val,maxn,minn;
}tree[N*3];
Tree neutral_element={0,INT_MIN,INT_MAX};
Tree initi(Tree t,int n,int range){
    return {t.val+(n*range),t.maxn+n,t.minn+n};
}
Tree merge(const Tree a,const Tree b){
    return {a.val+b.val, max(a.maxn,b.maxn), min(a.minn,b.minn)};
}
void init(int node,int b,int e){
    if(b==e){
        tree[node]=initi({0,0,0},arr[b],(e-b+1));
        return;
    }
    int mid=(b+e)>>1;
    init(node<<1,b,mid);
    init((node<<1)+1,mid+1,e);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
void update(int node,int b,int e,int i,int j){
    if(lazy[node]!=0){
        tree[node]=initi(tree[node],lazy[node],(e-b+1));
        if(b!=e){
            lazy[node<<1] += lazy[node];
            lazy[(node<<1)+1] += lazy[node];
        }lazy[node]=0;
    }
    if(e<i || j<b) return;
    if(b>=i && e<=j){
        tree[node]=initi(tree[node],1,(e-b+1));
        if(b!=e){
            lazy[node<<1]+=1;
            lazy[(node<<1)+1]+=1;
        }
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,j);
    update((node<<1)+1,mid+1,e,i,j);
    tree[node]=merge(tree[node<<1],tree[(node<<1)+1]);
}
Tree query(int node,int b,int e,int i,int j){
    if(lazy[node]!=0){
        tree[node]=initi(tree[node],lazy[node],(e-b+1));
        if(b!=e){
            lazy[node<<1]+=lazy[node];
            lazy[(node<<1)+1]+=lazy[node];
        }lazy[node]=0;
    }
    if(e<i || j<b) return neutral_element;
    if(b>=i && e<=j) return tree[node];
    int mid=(b+e)>>1;
    Tree n=query(node<<1,b,mid,i,j);
    Tree m=query((node<<1)+1,mid+1,e,i,j);
    return merge(n,m);
}
int main(void){
    memset(lazy,0,sizeof(lazy));
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    init(1,0,n-1);
    while(q--){
        int a,b,c;cin>>a>>b>>c;
        if(a==0){
            update(1,0,n-1,b,c);
        }else if(a==1){
            Tree  ans= query(1,0,n-1,b,c);
            if(ans.maxn==0 && ans.minn==0) cout<<(c-b+1)<<endl;
            else cout<<(ans.maxn-ans.minn+1)/3<<endl;
        }
    }
}
/*0 0 0 0 =>4
0 1 1 0
0 2 2 1
0 2 2 1 => 1
1 3 3 2
1 3 3 2 => 0
1 3 3 2 => 2
*/