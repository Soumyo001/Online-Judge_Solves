#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
double ans[N];
int n;
void inputGraph(){
    for(int i=1;i<=(n-1);i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
double dfs(int vertex,int par){
    int flag=1;
    double c=0,k=0;
    for(auto& i:graph[vertex]){
        if(i==par) continue;
        flag=0;
        k+=dfs(i,vertex);
        //ans[vertex]+=ans[i];
        c++;
    }
    //return (!flag ? ans[vertex] = (ans[vertex]/graph[vertex].size())+1 : 0);
    //cout<<vertex<<" "<<ans[vertex]<<" "<<endl;
    return !flag? k/c+1:0;
}
int main(void){
    cin>>n;
    inputGraph();
    cout<<fixed<<setprecision(8)<<dfs(1,0);
}