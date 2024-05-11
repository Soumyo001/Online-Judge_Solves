#include<bits/stdc++.h>
using namespace std;
const int N=501;
vector<char> graph[N];
int dx[]={0,  0, 1, -1, 1, -1,  1, -1};
int dy[]={-1, 1, 0,  0, 1,  1, -1, -1};
bool vis[N*N];
int flood=0,danger=0,n;
void inputGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            graph[i].push_back(c);
        }
    }
}
bool isValid(int x,int y,char c){
    return x>=0 && y>=0 && x<n && y<n && vis[x*n+y]==false && graph[x][y]==c;
}
void floodFill1(int x,int y){
    vis[x*n+y]=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(isValid(nx,ny,'*')) floodFill1(nx,ny);
    }
}
void floodFill(int x,int y){
    vis[x*n+y]=true;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(isValid(nx,ny,'#')) floodFill(nx,ny);
        else if(isValid(nx,ny,'*')){
                danger++;
                floodFill1(nx,ny);
        }
    }
}
int main(void){
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
        flood=danger=0;
        for(int i=0;i<=n*n;i++) {
            vis[i]=false;
        }
        for(int i=0;i<n;i++) graph[i].clear();
        inputGraph();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]=='#' && vis[i*n+j] == false) {
                    flood++;
                    floodFill(i,j);
                }
            }
        }
        cout<<"Case "<<z<<": "<<flood<<" "<<danger<<endl;
    }
}