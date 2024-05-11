#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int>graph[N];
int n,m;
long long s=0;int t1=0;
int dx[]={0, 0, 1,-1,1,-1, 1,-1};
int dy[]={1,-1, 0, 0,1, 1,-1,-1};
void Clear(){
    for(int i=0;i<n;i++){
        graph[i].clear();
    }
}
void inputGrid(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;cin>>a;
            graph[i].push_back(a);
        }
    }
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && graph[x][y]==1;
}
void dfs(int x,int y){
    graph[x][y]=2;
    s++;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(valid(nx,ny)) dfs(nx,ny);
    }
}
int main(void){
    int t;cin>>t;
    while(t--){
        t1=0;
        cin>>n>>m;
        Clear();
        inputGrid();
        long long mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j]==1){
                    s=0;
                    dfs(i,j);
                    mx=max(mx,s);
                    t1++;
                }
            }
        }
        cout<<t1<<" "<<mx<<endl;
    }
}