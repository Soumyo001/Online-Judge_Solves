#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
vector<int> sk,st;
int vis[N];
int n,k;
void inputGraph(){
    for(int i=0;i<k;i++){
        int x;cin>>x;sk.push_back(x);
    }
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        for(int j=0;j<x;j++){
            int c;cin>>c;
            graph[i].push_back(c);
        }
    }
}
bool dfs(int vertex){
    vis[vertex]=1;
    //cout<<vertex<<" ";
    bool isL=false;
    for(auto& i:graph[vertex]){
        if(vis[i]==2) continue;
        if(vis[i]==1) return true;
        if(vis[i]==0) isL |= dfs(i);
    }
    st.push_back(vertex);
    vis[vertex]=2;
    return isL;
}
int main(void){
    cin>>n>>k;
    inputGraph();
    for(auto& i:sk){
        if(vis[i]==0){
            if(dfs(i)){
                cout<<-1<<endl;exit(0);
            }
        }
    }
    cout<<st.size()<<endl;
    for(auto& i:st) cout<<i<<" ";
}