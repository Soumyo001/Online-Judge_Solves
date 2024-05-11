#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
char graph[N][N];
bool vis[N][N];
int n,m;
void inputGraph(){
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>graph[i][j];
}
int main(void){
    cin>>n>>m;
    inputGraph();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(graph[i][j-1]=='*' && graph[i][j+1]=='*' && graph[i-1][j]=='*' && graph[i+1][j]=='*' && graph[i][j]=='*'){
                int up=i,down=i,left=j,right=j;
                while(up>=1 && graph[up][j]=='*') vis[up--][j]=true;
                while(down<=n && graph[down][j]=='*') vis[down++][j]=true;
                while(left>=1 && graph[i][left]=='*') vis[i][left--]=true;
                while(right<=m && graph[i][right]=='*') vis[i][right++]=true;

                for(int k=1;k<=n;k++){
                    for(int l=1;l<=m;++l){
                        if(vis[k][l]!=(graph[k][l]=='*')){
                            cout<<"NO"<<endl;return 0;
                        }
                    }
                }
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}