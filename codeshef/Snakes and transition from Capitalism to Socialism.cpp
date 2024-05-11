#include<bits/stdc++.h>
using namespace std;
const int N=610;
vector<int> graph[N];
vector<pair<int,int>> v;
int level[N*N],status[N*N];
int n,m,mx=INT_MIN;
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
void Clear(){
    for(int i=0;i<n;i++) graph[i].clear();
    mx=INT_MIN;
    v.clear();
}
void inputGraph(){
    Clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u;cin>>u;
            graph[i].push_back(u);
            mx=max(u,mx);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==mx) v.push_back(make_pair(i,j));
        }
    }
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && status[x*m+y]==1;
}
void initiStatus(){
    for(int i=0;i<n*m;i++) {status[i]=1;level[i]=0;}
}
int multiBfs(){
    initiStatus();
    queue<pair<int,int>> q;
    for(const auto& i:v){
        q.push(make_pair(i.first,i.second));
        status[i.first*m+i.second]=2;
    }
    int ans=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        status[x*m+y]=3;
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny)){
                q.push({nx,ny});
                status[nx*m+ny]=2;
                level[nx*m+ny]=level[x*m+y]+1;
                ans=max(ans,level[nx*m+ny]);
            }
        }
    }
    return ans;
}
int main(void){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        inputGraph();
        cout<<multiBfs()<<endl;
    }
}