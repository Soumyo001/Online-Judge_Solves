#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
vector<int>graph[N];
vector<int>values[N];
int val[N];
int n;
void inputGraph(){
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex,int par){
    values[vertex].push_back(val[vertex]);
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        dfs(i,vertex);
        for(auto& j:values[i]) values[vertex].push_back(j);
    }
}
bool cmp(const pair<int,int>& a,const pair<int,int>& b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
}
int main(void){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    inputGraph();
    dfs(1,0);
    int q;cin>>q;
    //for(int i=1;i<=n;i++) {for(auto& j:values[i]) cout<<i<<" "<<j<<endl;}
    while(q--){
        unordered_map<int,long long>m;
        int a,b;cin>>a>>b;
        for(auto& i:values[a]) m[i]++;
        for(auto& i:values[b]) m[i]++;
        vector<pair<int,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp);
        //for(auto& i:v) cout<<i.first<<" "<<i.second<<endl;
        //for(auto& i:vals) cout<<i<<" ";
        //cout<<endl;
        long long mx=LLONG_MIN;
        int node=-1;
        for(auto& i:v){
            if(mx<=i.second){
                if(mx==i.second) {node=(node>i.first ? i.first:node);continue;}
                mx=i.second;
                node=i.first;
            }
        }
        cout<<node<<endl;
    }
}