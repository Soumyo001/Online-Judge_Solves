#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int inf=1e9+10;
int graph[N][N],dist[N],status[N];
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int n,m;cin>>n>>m;
        graph[n][m]=1;
        graph[m][n]=1;
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
        cout<<val<<" ";
        status[val]=3;
        for(int i=1;i<=number_of_nodes;i++){
            if(graph[val][i] && status[i]==1){
                q.push(i);
                status[i]=2;
                dist[i]=dist[val]+1;
            }
        }
    }
    cout<<endl;
}
void printDist(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        cout<<"Level of "<<i<<" is "<<dist[i]<<endl;
    }
}
int main(void){
    //memset(dist,inf,sizeof(dist));
    int n,e,s;cin>>n>>e>>s;
    inputGraph(e);
    bfs(s,n);
    printDist(n);
}