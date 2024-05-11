#include<bits/stdc++.h>
using namespace std;
const int N=110;
vector<char> graph[N];
int dist[N*N],status[N*N];
int n,m;
pair<int,int> loc,dest;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void Clear(){
    for(int i=0;i<n;i++) graph[i].clear();
}
void inputGrid(){
    Clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             char c;cin>>c;
             if(c=='$') loc.first=i,loc.second=j;
             else if(c=='#') dest.first=i,dest.second=j;
             graph[i].push_back(c);
        }
    }
}
void initiStatus(){
    for(int i=0;i<n*m;i++) dist[i]=0,status[i]=1;
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && graph[x][y]!='*' && status[x*m+y]==1;
}
void bfs(){
    initiStatus();
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
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        inputGrid();
        //if(dest.first==0 && dest.second==0) {cout<<-1<<endl;return 0;}
        bfs();
        if(dist[dest.first*m+dest.second]==0) cout<<-1<<endl;
        else cout<<dist[dest.first*m+dest.second]<<endl;
    }
}