#include<bits/stdc++.h>
using namespace std;
const int N=60;
char g[N][N];
bool vis[N][N];
int n,a,b,c,d;
vector<pair<int,int>> s,e;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void inputGraph(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>g[i][j];
}
bool isValid(int x,int y){
    return x>=1 && y>=1 && x<=n && y<=n && g[x][y]=='0' && !vis[x][y];
}
void dfs(int x,int y,vector<pair<int,int>>& v){
    vis[x][y]=true;
    v.push_back({x,y});
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(isValid(nx,ny)) dfs(nx,ny,v);
    }
}
int main(void){
    cin>>n;
    cin>>a>>b>>c>>d;
    inputGraph();
    dfs(a,b,s);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vis[i][j]=false;
    dfs(c,d,e);
    int mini=INT_MAX;
    for(auto& i:s){
        for(auto& j:e){
            int dist=pow((j.first-i.first),2)+pow((j.second-i.second),2);
            mini=min(mini,dist);
        }
    }
    // for(auto i:s) cout<<i.first<<" "<<i.second<<endl;
    // for(auto i:e) cout<<i.first<<" "<<i.second<<endl;
    // for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) cout<<g[i][j]<<" ";cout<<endl;}
    cout<<mini<<endl;
}