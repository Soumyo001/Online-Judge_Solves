#include<bits/stdc++.h>
using namespace std;
const int N=1011;
int graph[N][N];
int n,m,totN=0;
vector<pair<int,int>> movements={{0,-1},{0,1},{1,0},{-1,0}};
void inputGrid(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>graph[i][j];
            if(graph[i][j]==1) totN+=1;
        }
    }
}
bool valid(int x,int y){
    return x>=1 && y>=1 && x<=n && y<=m && graph[x][y]==1;
}
void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    graph[x][y]=0;
    totN--;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<movements.size();i++){
            int nx=x+movements[i].first;
            int ny=y+movements[i].second;
            if(valid(nx,ny)){
                q.push({nx,ny});
                totN-=1;
                graph[nx][ny]=0;
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;
    cin>>n>>m>>q;
    inputGrid();
    while(q--){
        int x,y;cin>>x>>y;
        if(graph[x][y]==1) bfs(x,y);
        cout<<totN<<endl;
    }
}