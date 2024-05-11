#include<bits/stdc++.h>
using namespace std;
const int N=600;
char g[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r,c;
void inputGraph(){
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++) cin>>g[i][j];
}
bool isValid(int x,int y){
    return x>=1 && y>=1 && x<=r && y<=c;
}
int main(void){
    cin>>r>>c;
    inputGraph();
    int flag=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(g[i][j]=='W'){
                flag=1;
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(isValid(nx,ny)){
                        if(g[nx][ny]=='S'){
                            cout<<"No\n";
                            return 0;
                        }else if(g[nx][ny]=='.') g[nx][ny]='D';
                    }
                }
            }
        }
    }
    //if(!flag) g[int(r/2)+1][int(c/2)+1]='D';
    cout<<"Yes\n";
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++) cout<<g[i][j];
        cout<<endl;
    }
}
//answer is correct, check the problem on "https://codeforces.com/problemset/problem/948/A" for verfication.