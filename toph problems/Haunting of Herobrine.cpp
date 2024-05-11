#include<bits/stdc++.h>
using namespace std;
const int N=30;
vector<char>graph[N];
int rs=15,n,ans;
bool vis[N][N];
pair<int,int> si;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void inputGrid(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            if(c=='@') si.first=i,si.second=j;
            graph[i].push_back(c);
        }
    }
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<n && graph[x][y]!='.' && vis[x][y]==false;
}
void dfs(int x,int y){
    vis[x][y]=true;
    //cout<<rs<<" ";
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(valid(nx,ny)) {
            if(graph[nx][ny]=='$') rs=15;
            else if(graph[nx][ny]=='#') ans=rs;
            else rs--;
            dfs(nx,ny);
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    inputGrid();
    dfs(si.first,si.second);
    if(ans>=1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}