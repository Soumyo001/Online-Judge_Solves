#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
bool vis[N];
int n;
void inputGraph(){
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
}
void dfs(int vertex){
    vis[vertex]=true;
    for(auto& i:graph[vertex]) if(!vis[i]) dfs(i);
}
int main(void){
    cin>>n;
    inputGraph();
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            ++ans;
        }
    }
    cout<<ans<<endl;
}