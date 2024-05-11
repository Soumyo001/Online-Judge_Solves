#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int>graph[N];
int n,m,sum=0;
bool vis[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void inputGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;cin>>x;
            graph[i].push_back(x);
        }
    }
}
bool isValid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && !vis[x][y] && graph[x][y]!=0;
}
void dfs(int x,int y){
    vis[x][y]=true;
    sum=sum+graph[x][y];
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(isValid(nx,ny)) dfs(nx,ny);
    }
}
int main(void){
    int t;cin>>t;
    for(int z=0;z<t;z++){
        cin>>n>>m;
        inputGraph();
        for(int i=0;i<=(n);i++){
            for(int j=0;j<=(m);j++) vis[i][j]=false;
        }
        for(int i=0;i<=n;i++) graph[i].clear();
        sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && graph[i][j]!=0) {
                    dfs(i,j);
                    ans=max(sum,ans);
                    sum=0;
                }
            }
        }
        cout<<ans<<endl;
    }
}