#include<bits/stdc++.h>
using namespace std;
const int N=110;
vector<int> graph[N];
int level[N*N],status[N*N];
int n,m;
int dx[]={0, 0, 1, -1, 1, -1,  1, -1};
int dy[]={1,-1, 0,  0, 1,  1, -1, -1};
void inputGrpah(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u;cin>>u;
            graph[i].push_back(u);
        }
    }
}
void initiStatus(){
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         status[i][j]=1;
    //         level[i][j]=0;
    //     }
    // }
    for(int i=0;i<n*m;i++){status[i]=1;level[i]=0;}
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && status[x*m+y]==1;
}
void multiBfs(vector<pair<int,int>>& source){
    initiStatus();
    queue<pair<int,int>>q;
    for(auto& i:source){
        q.push({i.first,i.second});
        status[i.first*m+i.second]=2;
    }
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
            }
        }    
    }
}
void printGrid(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<level[i*m+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--){
        int s;
        cin >> n >> m >> s;
        inputGrpah();
        vector<pair<int,int>>v(s + 1, {0,0});
        for (int i = 0; i < s; i++) cin>>v[i].first>>v[i].second;
        multiBfs(v);
        printGrid();
    }
}