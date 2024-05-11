#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
int dist[N][N],parent[N][N];
int main(void){
    int n,e;cin>>n>>e;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0,parent[i][j]=-1;
            else dist[i][j]=INT_MAX,parent[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int u,v,wt;cin>>u>>v>>wt;
        dist[u][v]=wt;
        parent[u][v]=u;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    parent[i][j]=k;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]!=INT_MAX) cout<<dist[i][j]<<"\t";
            else cout<<"INF"<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<parent[i][j]<<"\t";
        }
        cout<<endl;
    }
}