#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<char>graph[N];
vector<int>co;
int n,m,ct=0;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
void inputGrid(){
    for(int i=0;i<n;i++) graph[i].clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            graph[i].push_back(c);
        }
    }
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && graph[x][y]=='.';
}
void dfs(int x,int y){
    graph[x][y]='#';
    ct++;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(valid(nx,ny)) dfs(nx,ny);
    }
}
int main(void){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        inputGrid();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j]=='.'){
                    dfs(i,j);
                    co.push_back(ct);
                    ct=0;
                }
            }
        }
        cout<<co.size()<<endl;
        for(auto& i:co) cout<<i<<" ";
        cout<<endl;
        co.clear();
    }
}