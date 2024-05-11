#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int inf=1e9+10;
int dist[N][N];
int main(void){
     int n,m;cin>>n>>m;
    for(int i=1;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=inf;
        }
    }
    while(m--){
        int n,e,w;cin>>n>>e>>w;
        dist[n][e]=w;
    }
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(dist[i][k]!=inf && dist[k][j]!=inf) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    bool negcycle=false;
    for(int i=1;i<=n;i++){
        if(dist[i][i]<0) negcycle=true;
    }
    if(negcycle) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            cout<<dist[0][i]<<(i==n?"\n":" ");
        }
    }
}