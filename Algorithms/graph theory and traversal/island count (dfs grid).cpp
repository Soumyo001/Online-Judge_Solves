#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int> grid[N];
int n,m;
bool vis[N*N];
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
void inputGrid(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u;cin>>u;
            grid[i].push_back(u);
        }
    }
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && grid[x][y]==1;
}
void dfs(int x,int y){
    //vis[x*m+y]=true;
    grid[x][y]=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!valid(nx,ny)) continue;
        dfs(nx,ny);
    }
}
int main(void){
    cin>>n>>m;
    inputGrid();
    int ct=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0){
                dfs(i,j);
                ct++;
                //cout<<ct<<" ";
            }
        }
    }
    cout<<ct<<endl;
}