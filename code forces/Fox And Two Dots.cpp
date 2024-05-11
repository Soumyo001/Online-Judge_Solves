#include<bits/stdc++.h>
using namespace std;
const int N=60;
char g[N][N];
bool vis[N][N];
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void inputGraph(){
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>g[i][j];
}
bool isValid(int x,int y,char c){
    return x>=1 && y>=1 && x<=n && y<=m && g[x][y]==c;
}

bool dfs(int x,int y,int px,int py,char c){
    vis[x][y]=true;
    bool isC=false;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if((vis[nx][ny] && nx==px && ny==py) || !isValid(nx,ny,c)) continue;
        if(vis[nx][ny]) return true;
        isC|=dfs(nx,ny,x,y,c);
    }
    return isC;
}
int main(void){
    cin>>n>>m;
    inputGraph();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]){
                if(dfs(i,j,-1,-1,g[i][j])){
                    cout<<"Yes"<<endl;return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
}