#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a,b,c,d;
int level[N][N],status[N][N];
int dx1[]={0, 0, 1,-1,1,-1, 1,-1};
int dy1[]={1,-1, 0, 0,1, 1,-1,-1};
void initiStatus(){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            status[i][j]=1;
        }
    }
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<a && y<b && status[x][y]==1;
}
void bfs(int sx,int sy){
    initiStatus();
    queue<pair<int,int>>q;
    q.push({sx,sy});
    status[sx][sy]=2;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        status[x][y]=3;
        for(int i=0;i<8;i++){
            int nx=x+dx1[i];
            int ny=y+dy1[i];
            if(valid(nx,ny)){
                q.push({nx,ny});
                status[nx][ny]=2;
                level[nx][ny]=level[x][y]+1;
            }
        }
    }
}
void printPattern(){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++) cout<<level[i][j]<<" ";
        cout<<endl;
    }
}
int main(void){
    cin>>a>>b>>c>>d;
    bfs(c,d);
    printPattern();
}