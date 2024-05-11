#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<char>graph[N];
int status[N*N];
int n,m;
int dx[]={1,0,0,-1};
int dy[]={0,-1,1,0};
char dir[]={'D','L','R','U'};
void Clear(){
    for(int i=0;i<n;i++) graph[i].clear();
}
void inputGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            graph[i].push_back(c);
        }
    }
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && graph[x][y]=='.' && status[x*m+y]==1;
}
string bfs(int sx,int sy,int dx1,int dy1){
    for(int i=0;i<n*m;i++) status[i]=1;
    queue<pair<int,int>>q;
    queue<string> str;
    q.push({sx,sy});
    str.push("");
    status[sx*m+sy]=2;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        string temp=str.front();
        str.pop();
        if(x==dx1 && y==dy1) return temp;
        status[x*m+y]=3;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny)){
                q.push({nx,ny});
                string f=temp+dir[i];
                str.push(f);
                status[nx*m+ny]=2;
            }
        }
    }
    return "Impossible";
}
int main(void){
    cin>>n>>m;
    inputGraph();
    int q;cin>>q;
    while(q--){
        int sx,sy,dx1,dy1;
        cin>>sx>>sy>>dx1>>dy1;
        sx--;
        sy--;
        dx1--;
        dy1--;
        Clear();
        cout<<bfs(sx,sy,dx1,dy1)<<endl;
    }
}