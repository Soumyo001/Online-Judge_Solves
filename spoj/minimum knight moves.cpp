#include<bits/stdc++.h>
using namespace std;
int kx[]={2,-2,1,-1,-2,2,-1,1};
int ky[]={1,1,2,2,-1,-1,-2,-2};
// const int N=1e5+7;
// vector<int>graph[N];
int vis[8*8],level[8*8];
int getX(string a){
    return a[0]-'a';
}
int getY(string a){
    return a[1]-'1';
}
bool valid(int x,int y){
    return x<8 && y<8 && x>=0 && y>=0;
}
void reset(){
    for(int i=0;i<8*8;i++) {level[i]=0;vis[i]=1;}
}
int bfs(string source,string dest){
    reset();
     int sx=getX(source);
     int sy=getY(source);
     int dx=getX(dest);
     int dy=getY(dest);
     queue<pair<int,int>>q;
     q.push({sx,sy});
     vis[sy*8+sx]=2;
     while(!q.empty()){
        auto x=q.front().first;
        auto y=q.front().second;
        q.pop();
        vis[y*8+x]=3;//ans is also correct without this line
        for(int i=0;i<8;i++){
            int nx=x+kx[i];
            int ny=y+ky[i];
            if(valid(nx,ny) && vis[ny*8+nx]==1){
                q.push({nx,ny});
                vis[ny*8+nx]=2;
                level[ny*8+nx]=level[y*8+x]+1;
            }
        }
    }
    return level[dy*8+dx];
}
int main(void){
    int t;cin>>t;
    while(t--){
        string a,b;cin>>a>>b;
        cout<<bfs(a,b)<<endl;
    }
}