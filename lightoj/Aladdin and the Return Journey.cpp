#include<bits/stdc++.h>
using namespace std;
const int N=3e4+5;
int tree[N*3],arr[N],parent[N];
int n;
vector<int> graph[N];
void inputGraph(){
    for(int i=1;i<=(n-1);i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void init(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];return;
    }
    int mid=(b+e)>>1;
    init(node<<1,b,mid);
    init((node<<1)+1,mid+1,e);
    tree[node]=tree[node<<1]+tree[(node<<1)+1];
}
void update(int node,int b,int e,int i,int x){
    if(e<i || i<b) return;
    if(b>=i && e<=i){
        tree[node]=x;
        arr[b]=x;
        return;
    }
    int mid=(b+e)>>1;
    update(node<<1,b,mid,i,x);
    update((node<<1)+1,mid+1,e,i,x);
    tree[node]=tree[node<<1]+tree[(node<<1)+1];
}
void dfs(int vertex,int par){
    parent[vertex]=par;
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
    }
}
vector<int> lca(int s){
    vector<int> v;
    while(s!=-1){
        v.push_back(s);
        s=parent[s];
    }
    return v;
}
void solve(){
    for(int i=1;i<=N*3;i++) tree[i]=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<=n;i++) parent[i]=0,graph[i].clear();
    init(1,0,n-1);
    inputGraph();
    dfs(0,-1);
    int q;cin>>q;
    while(q--){
        int x,i,j;cin>>x>>i>>j;
        if(x==0){
            vector<int> a=lca(i);
            vector<int> b=lca(j);
            // for(auto i:a) cout<<i<<" ";cout<<endl;
            // for(auto i:b) cout<<i<<" ";cout<<endl;
            int sum=0;
            for(int l=0;l<min(a.size(),b.size());l++){
                if(a[l]==b[l]){
                    sum+=arr[a[l]];break;
                    //cout<<a[l]<<" "<<b[l]<<endl;
                }
                sum+=arr[a[l]];
                sum+=arr[b[l]];
                //cout<<a[l]<<" "<<b[l]<<endl;
            }
            cout<<sum<<endl;
        }else if(x==1){
            update(1,0,n-1,i,j);
        }
    }
}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": \n";
        string line;getline(cin,line);
        solve();
    }
}