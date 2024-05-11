#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int inf=1e9+7;
int dist[N][N];
int main(void){
    int n,e;cin>>n>>e;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=inf;
        }
    }
    for(int i=0;i<e;i++){
        int n,m,wt;cin>>n>>m>>wt;
        dist[n][m]=wt;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=inf && dist[k][j]!=inf)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==inf) cout<<"I"<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}