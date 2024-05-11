#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
vector<int>graph[N];
int dist[N*N];
queue<pair<int,int>>q;
int mx=0;
int n,m;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
void inputGrid(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;cin>>a;
            graph[i].push_back(a);
            if(a==2) q.push({i,j});
        }
    }
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && graph[x][y]==1;
}
void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny)){
                graph[nx][ny]=2;
                q.push({nx,ny});
                dist[nx*m+ny]=dist[x*m+y]+1;
                mx=max(mx,dist[nx*m+ny]);
            }
        }
    }
}
int main(void){
    cin>>n>>m;
    inputGrid();
    bfs();
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {if(graph[i][j]==1) {cout<<-1<<endl;return 0;}}
    cout<<mx<<endl;
}