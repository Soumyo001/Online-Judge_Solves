#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<char> g[N];
bool vis[N][N];
int n,m;
void inputGraph(){
    for(int i=0;i<n;i++){
        g[i].clear();
        for(int j=0;j<m;j++){
            char c;cin>>c;
            g[i].push_back(c);
        }
    }
}
bool isValid(int x,int y,char c){
    return x>=0 && y>=0 && x<n && y<m && g[x][y]==c;
}
void dfs(int x,int y){
    if(isValid(x+1,y,'.')){
        g[x+1][y]='*';
        g[x][y]='.';
        dfs(x+1,y);
    }else if(isValid(x+1,y,'*') || isValid(x+1,y,'o')) return;
}
void solve(){
    cin>>n>>m;
    inputGraph();
    for(int i=n-2;i>=0;--i){
        for(int j=0;j<m;j++){
            if(g[i][j]=='*') dfs(i,j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<g[i][j];
        cout<<endl;
    } 
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}