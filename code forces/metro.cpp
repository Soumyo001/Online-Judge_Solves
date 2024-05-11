#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int>graph[N];
int a[N];
int b[N];
bool vis[N];
int n,s;
bool dfs(int vertex){
    vis[vertex]=true;
    if(vertex==s) return true;
    bool isPossible=false;
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        isPossible |= dfs(i);
    }
    return isPossible;
}
int main(void){
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    if(a[1]==0 || (a[s]==0 && b[s]==0)){
        cout<<"NO\n";
        return 0;
    }
    if(a[s]==1){
        cout<<"YES\n";
        return 0;
    }
    int flag=0;
    if(a[s]==0){
        for(int i=s;i<=n;i++){
            if(a[i] && b[i]){
                flag=1;break;
            }
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    // if(a[s]==0) s=n+(n-s)+1;
    // int node=1;
    // for(int i=2;i<=n;i++){
    //     if(a[i]==1){
    //         graph[node].push_back(i);
    //         node=i;
    //     }
    // }
    // for(int i=n,x=1;i>=1;i--,x++){
    //     if(b[i]==1){
    //         graph[node].push_back(n+x);
    //         node=n+x;
    //     }
    // }
    // if(dfs(1)) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
}