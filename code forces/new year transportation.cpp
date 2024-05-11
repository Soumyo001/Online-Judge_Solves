#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
int n,t;
int arr[N];
bool vis[N];
void inputGraph(){
    for(int i=1;i<=(n-1);i++) cin>>arr[i];
    for(int i=1;i<=(n-1);i++) graph[i].push_back(i+arr[i]);
}
bool dfs(int vertex){
    vis[vertex]=true;
    if(vertex==t) return true;
    bool isPossible=false;
    for(auto& i:graph[vertex]){
        if(vis[i]) continue;
        return isPossible |= dfs(i);
    }
    return false;
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>t;
    inputGraph();
    if(dfs(1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}