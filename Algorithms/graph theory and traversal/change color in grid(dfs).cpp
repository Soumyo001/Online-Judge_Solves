#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
vector<int>grid[N];
bool vis[N*N];
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void inputGrid(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u;cin>>u;
            grid[i].push_back(u);
        }
    }
}
bool valid(int x,int y,int initiColor){
    return x>=0 && y>=0 && x<n && y<m && grid[x][y]==initiColor; //&& vis[x*m+y]==false;
}
void dfs(int i,int j,int initiColor,int newColor){
   // vis[i*m+j]=true;
    grid[i][j]=newColor;
    for(int x=0;x<4;x++){
        int ni=i+dx[x];
        int nj=j+dy[x];
        if(valid(ni,nj,initiColor)) dfs(ni,nj,initiColor,newColor);
    }
}
int main(void){
    cin>>n>>m;
    inputGrid();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0) dfs(i,j,1,2);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}