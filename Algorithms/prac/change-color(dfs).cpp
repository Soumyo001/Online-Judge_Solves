#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int>matrix[N];
//bool vis[N*N];
int dx[]={0,  0, 1, -1};
int dy[]={1, -1, 0, 0};
int n,m;
void inputGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u;cin>>u;
            matrix[i].push_back(u);
        }
    }
}
bool isValid(int x,int y,int initiColor){
    return x>=0 && y>=0 && x<n && y<m && matrix[x][y]==initiColor;
}
void floodFill(int x,int y,int initiColor, int newColor){
    matrix[x][y]=newColor;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(isValid(nx,ny,initiColor)) floodFill(nx,ny,initiColor,newColor);
    }
}
void printGrid(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
int main(void){
    cin>>n>>m;
    inputGraph();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1) floodFill(i,j,1,2);
        }
    }
    printGrid();
}