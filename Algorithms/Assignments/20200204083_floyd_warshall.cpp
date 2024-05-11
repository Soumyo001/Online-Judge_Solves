#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dist[N][N],parent[N][N];
int n,e;
void inputGraph(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) {
                dist[i][j]=0;
                parent[i][j]=-1;
            }
            else dist[i][j]=numeric_limits<int>::max();
        }
    }
    for(int i=0;i<e;i++){
        int u,v,wt;cin>>u>>v>>wt;
        dist[u][v]=wt;
        parent[u][v]=u;
    }
}
void floyd_warshall(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=numeric_limits<int>::max() && dist[k][j]!=numeric_limits<int>::max() && dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    parent[i][j]=k;
                }
            }
        }
    }
}
void printPath(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==numeric_limits<int>::max()) cout<<"INF\t";
            else cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
void printParent(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<parent[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(void){
    cin>>n>>e;
    inputGraph();
    floyd_warshall();
    printPath();
    printParent();
}