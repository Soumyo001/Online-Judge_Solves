#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
int vis[N][N];
int p_x[]={0,1};
int p_y[]={1,0};
pair<int,int> idx;
int cost_m=INT_MAX;
bool flag=true;
bool valid(int x,int y,vector<string> flow,vector<vector<int>> cost,int n,int m){
    return x>=0 && y>=0 && x<n && y<m && flow[x][y]=='.' && vis[x][y]==0;
}
bool valid1(int x,int y,vector<string> flow,vector<vector<int>> cost,int n,int m){
    return x>=0 && y>=0 && x<n && y<m && flow[x][y]=='.' && vis[x][y]==1;
}
void dfs(int x,int y,vector<string> flow,vector<vector<int>> cost,int n,int m){
    vis[x][y]=1;
    cost_m=min(cost_m,cost[x][y]);
    for(int i=0;i<2;i++){
        int nx=x+p_x[i];
        int ny=y+p_y[i];
        if(valid(nx,ny,flow,cost,n,m)) dfs(nx,ny,flow,cost,n,m);
        else if(valid1(nx,ny,flow,cost,n,m)){
            idx.first=nx;
            idx.second=ny;
            //cout<<nx<<" "<<ny<<endl;
        }
    }
}
int buildDam (int N, int M, vector<string> flow, vector<vector<int> > cost) {
    dfs(0,0,flow,cost,N,M);
    return 0;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<string> flow(N);
    for(int i_flow = 0; i_flow < N; i_flow++)
    {
    	cin >> flow[i_flow];
    }
    vector<vector<int> > cost(N, vector<int>(M));
    for (int i_cost = 0; i_cost < N; i_cost++)
    {
    	for(int j_cost = 0; j_cost < M; j_cost++)
    	{
    		cin >> cost[i_cost][j_cost];
    	}
    }

    int out_;
    cost_m=min(flow[0][0],flow[N-1][M-1]);
    out_ = buildDam(N, M, flow, cost);
   // cout<<out_;
    cout << out_<<" "<<idx.first<<" "<<idx.second<<" "<<vis[N-1][M-1];
}