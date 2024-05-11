#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>graph[N];
long long C[N],subtree_sum[N];
int idn[N],parent[N];
void dfs(int vertex,int par){
    subtree_sum[vertex]=C[vertex];
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
        subtree_sum[vertex]+=subtree_sum[i];
    }
}
void update(int index,int r,int newVal){
    if(index==0) return;
    subtree_sum[index]-=C[r];
    subtree_sum[index]+=newVal;
    update(parent[index],r,newVal);
}
int main(void){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>C[i];
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        idn[v]++;
        parent[v]=u;
        graph[u].push_back(v);
    }
    int root;
    for(int i=1;i<=n;i++){
        if(idn[i]==0){
            root=i;
            break;
        }
    }
    parent[root]=0;
    dfs(root,0);
    while(q--){
        int a;cin>>a;
        if(a==1){
            int b,c;cin>>b>>c;
            update(b,b,c);
            C[b]=c;
        }else if(a==2){
            int x;cin>>x;
            cout<<subtree_sum[x]<<endl;
        }
    }
}