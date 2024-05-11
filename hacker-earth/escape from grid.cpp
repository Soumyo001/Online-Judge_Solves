#include<bits/stdc++.h>
using namespace std;
const int N=110;
vector<int> graph[N];
int status[N*N],dist[N*N];
int n,m;
pair<int,int> loc;
int t=-1;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void inputGrid(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<m;j++){
            int a;cin>>a;
            graph[i].push_back(a);
            if(a==2) loc.first=i,loc.second=j;
        }
    }
}
bool valid(int x,int y){
    //if(((y==0 && x>=0 && x<n) || (x==(n-1) && y>=0 && y<m) || (y==(m-1) && x>=0 && x<n) || (x==0 && y>=0 && y<m)) && graph[x][y]==0 && status[x*m+y]==1) return false;
    return x>=0 && x<n && y>=0 && y<m && status[x*m+y]==1 && graph[x][y]==0;
}
int bfs(){
    for(int i=0;i<n*m;i++) status[i]=1;
    queue<pair<int,int>> q;
    q.push({loc.first,loc.second});
    status[loc.first*m+loc.second]=2;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        status[x*m+y]=3;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny)){
                q.push({nx,ny});
                status[nx*m+ny]=2;
                dist[nx*m+ny]=dist[x*m+y]+1;
                if((ny==0 && nx>=0 && nx<n) || (nx==(n-1) && ny>=0 && ny<m) || (ny==(m-1) && nx>=0 && nx<n) || (nx==0 && ny>=0 && ny<m)) return dist[nx*m+ny];
            }
        }
    }
    return -1;
}
int main(void){
    cin>>n>>m;
    if(n==1 && m==1) {cout<<0<<endl;return 0;}
    inputGrid();
    int x=loc.first,y=loc.second;
    if((y==0 && x>=0 && x<n) || (x==(n-1) && y>=0 && y<m) || (y==(m-1) && x>=0 && x<n) || (x==0 && y>=0 && y<m)) {cout<<0<<endl;return 0;}
    cout<<bfs()<<endl;
}