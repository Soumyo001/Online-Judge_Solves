#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>graph[N];
int status[N],dist[N];
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int n,m;cin>>n>>m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
}
void initiStatus(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++) status[i]=1;
}
void bfs(int source,int number_of_nodes){
    initiStatus(number_of_nodes);
    queue<int>q;
    q.push(source);
    status[source]=2;
    dist[source]=0;
    while(!q.empty()){
        int val=q.front();q.pop();
        status[val]=3;
        cout<<val<<" ";
        for(const auto& i:graph[val]){
            if(status[i]==1){
                q.push(i);
                status[i]=2;
                dist[i]=dist[val]+1;
            }
        }
    }
    cout<<endl;
}
void printLevel(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        cout<<"Level of "<<i<<" is "<<dist[i]<<endl;
    }
}
int main(void){
    int n,e,s;cin>>n>>e>>s;
    inputGraph(e);
    bfs(s,n);
    printLevel(n);
}