#include<bits/stdc++.h>
#define ll long long
#define inf 1e9+10;
using namespace std;
const int N=107;
int graph[N][N],dist[N][N],n,m;
int vis[N][N];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
void inputGrid(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
}
int grid(int time,int flash){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=inf;
        }
    }
    dist[0][0]=0;
    list<pair<int,int>>l;
    l.push_front({0,0});
    while(!l.empty()){
        auto x=l.front().first;auto y=l.front().second;l.pop_front();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                int t=0;
                if(abs(graph[nx][ny]-graph[x][y])%2!=flash) t=time;
                if(dist[nx][ny]>dist[x][y]+t){
                    dist[nx][ny]=dist[x][y]+t;
                    if(t!=0) l.push_back({nx,ny});
                    else l.push_front({nx,ny});
                }
            }
        }

    }
    return dist[n-1][m-1];
}
int main(void){
    int t;cin>>t;
    while(t--){
        int a,b;
        cin>>n>>m>>a>>b;
        inputGrid();
        if(grid(a,0)<grid(b,1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}