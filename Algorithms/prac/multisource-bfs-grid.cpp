#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int>matrix[N];
int dx[]={0,  0, 1, -1, 1, -1,  1, -1};
int dy[]={1, -1, 0,  0, 1,  1, -1, -1};
int level[N*N], status[N*N];
int n,m,s;
void inputGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u;cin>>u;
            matrix[i].push_back(u);
        }
    }
}
bool isValid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && status[x*m+y]==1;
}
void multibfs_grid(vector<pair<int,int>>& sources){
    for(int i=0;i<n*m;i++) status[i]=1,level[i]=0;
    queue<pair<int,int>> q;
    for(auto& i:sources) {q.push({i.first,i.second});status[i.first*m+i.second]=2;}
    while (!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        status[x*m+y]=3;
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isValid(nx,ny)){
                q.push({nx,ny});
                status[nx*m+ny]=2;
                level[nx*m+ny]=level[x*m+y]+1;
            }
        }
    }
}
void printLevel(){
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
        cin>>n>>m>>s;
        vector<pair<int,int>> sources;
        inputGraph();
        sources.resize(s+1,{0,0});
        for(int i=0;i<s;i++) cin>>sources[i].first>>sources[i].second;
        multibfs_grid(sources);
        printLevel();
    }
}