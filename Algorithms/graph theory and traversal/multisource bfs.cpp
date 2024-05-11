#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>> graph[N];
int status[N],level[N];
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int u,v,wt;cin>>u>>v;
        graph[u].push_back({v,1});
        graph[v].push_back({u,1});
    }
}
void initiStatus(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++) status[i]=1;
}
void multiBfs(vector<int>& source,int number_of_nodes){
    initiStatus(number_of_nodes);
    queue<int>q;
    for(auto& i:source){q.push(i);status[i]=2;}
    while(!q.empty()){
        int val=q.front();
        q.pop();
        status[val]=3;
        for(const auto& i:graph[val]){
            if (status[i.first]==1)
            {
                q.push(i.first);
                status[i.first]=2;
                level[i.first]=level[val]+1;
            }
            
        }
    }
}
void printDist(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        cout<<i<<" "<<level[i]<<endl;
    }
}
int main(void){
    int n,m,sc;cin>>n>>m>>sc;
    vector<int> source(sc+1,0);
    for(int i=0;i<sc;i++) cin>>source[i];
    inputGraph(m);
    multiBfs(source,n);
    printDist(n);
}