#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<bool>is_prime(N,1);
vector<int>lp(N,0),hp(N,0);
vector<int>graph[N];
int profit[N],n,subtree_sum[N];
void sieve(){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<N;i++){
        if(is_prime[i]){
            lp[i]=hp[i]=i;
            for(int j=i*2;j<N;j+=i){
                is_prime[j]=false;
                hp[j]=i;
                if(lp[j]==0) lp[j]=i;
            }
        }
    }
}
int get_num(int n){
    list<int>l;
    while(n>1){
        int prime_factor=hp[n];
        while(n%prime_factor==0){
            n/=prime_factor;
            l.push_back(prime_factor);
        }
    }
    l.unique();
    return l.size();
}
void Clear(){
    for(int i=1;i<=n;i++){
        graph[i].clear();
        profit[i]=subtree_sum[i]=0;
    }
}
void inputGraph(){
    for(int i=1;i<=(n-1);i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par){
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
        subtree_sum[vertex]+=subtree_sum[i];
    }
}
int main(void){
    sieve();
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>profit[i];
        inputGraph();
        for(int i=1;i<=n;i++) subtree_sum[i]=get_num(profit[i]);
        dfs(1,0);
        for(int i=1;i<=n;i++) cout<<subtree_sum[i]<<" ";
        cout<<endl;
        Clear();
    }
}