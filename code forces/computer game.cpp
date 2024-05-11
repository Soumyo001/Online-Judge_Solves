#include<bits/stdc++.h>
using namespace std;
vector<int>grid[2];
int n;
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,1,-1,-1};
int status[2][110];
void inputGraph(){
    grid[0].clear(),grid[1].clear();
    for(int i=0;i<2;i++){
        string s;cin>>s;
        for(int j=0;j<n;j++){
            grid[i].push_back(s[j]-'0');
            status[i][j]=1;
        }
    }
    --n;
}
bool isValid(int x,int y){
    return x>=0 && y>=0 && x<2 && y<=n && status[x][y]==1 && grid[x][y]==0;
}
void bfs(){
    queue<pair<int,int>>q;
    q.push({0,0});
    status[0][0]=2;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        status[x][y]=3;
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isValid(nx,ny)){
                q.push({nx,ny});
                status[nx][ny]=2;
                //cout<<nx<<" "<<ny<<" "<<i<<endl;
                if(nx==1 && ny==n){
                    cout<<"YES"<<endl;return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--){
        cin>>n;
        inputGraph();
        bfs();
    }
}