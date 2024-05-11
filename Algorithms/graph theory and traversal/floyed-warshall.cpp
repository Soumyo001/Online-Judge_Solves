#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dist[N][N];
int n,m;
int main(void){
    cin>>n>>m;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=numeric_limits<int>::max();
        }
    }
    for(int i=0;i<m;i++){
        int u,v,wt;cin>>u>>v>>wt;
        dist[u][v]=wt;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=numeric_limits<int>::max() && dist[k][j]!=numeric_limits<int>::max()){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==numeric_limits<int>::max()) cout<<"INF"<<"\t";
            else cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
}