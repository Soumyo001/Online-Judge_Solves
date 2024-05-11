#include<bits/stdc++.h>
using namespace std;
const int N=110;
vector<char>graph[N];
pair<int,int>team[2];
pair<int,int>mines[2];
int status[N*N],level[N*N];
int n;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void clear(){
    for(int i=0;i<n;i++) graph[i].clear();
}
void inputGrid(int number_of_grids){
    clear();
    int k=0,x=0;
    for(int i=0;i<number_of_grids;i++){
        for(int j=0;j<number_of_grids;j++){
            char c;
            cin>>c;
            if(c=='^'){
                team[k]={i,j};
                k++;
            }else if(c=='*'){
                mines[x]={i,j};
                x++;
            }
            graph[i].push_back(c);
        }
    }
}
void initiStatus(){
    for(int i=0;i<n*n;i++) {status[i]=1;level[i]=0;}
}
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<n && graph[x][y]!='#' && status[y*n+x]==1;
}
pair<int,int> bfs(pair<int,int> source,pair<int,int>dest,pair<int,int>dest1){
    initiStatus();
    queue<pair<int,int>>q;
    q.push({source.first,source.second});
    status[source.second*n+source.first]=2;
    while(!q.empty()){
        auto x=q.front().first;auto y=q.front().second;
        q.pop();
        status[y*n+x]=3;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny)){
                q.push({nx,ny});
                status[ny*n+nx]=2;
                level[ny*n+nx]=level[y*n+x]+1;
            }
        }
    }
    return {level[dest.second*n+dest.first],level[dest1.second*n+dest1.first]};
}
int main(void){
    int t;cin>>t;
    while(t--){
        cin>>n;
        inputGrid(n);
        auto a=bfs(team[0],mines[0],mines[1]);
        auto b=bfs(team[1],mines[0],mines[1]);
        swap(a.first,a.second);
        swap(b.first,b.second);
        if((a.first!=0 || a.second!=0) || (b.first!=0 || b.second!=0)){
            cout<<"Yes"<<endl;
            if((a.first==0 && a.second==0) || (b.first==0 && b.second==0)){
                if(a.first==0 && a.second==0) cout<<max(b.first,b.second)<<endl;
                else cout<<max(a.first,a.second)<<endl;
            }else if(a.first<b.first && a.second<b.second && b.first<b.second) cout<<max(a.first,a.second)<<endl;
            else cout<<min(max(a.first,b.second),max(a.second,b.first))<<endl;
        }else cout<<"No"<<endl;
    }
    // cin>>n;
    // inputGrid(n);
    // cout<<bfs(team[0],mines[1])<<endl;;
    // for (int i = 0; i < n; i++)
    // {
    //     for(int j=0;j<n;j++){
    //         cout<<level[j*n+i]<<" ";
    //     }
    //     cout<<endl;
    // }
    
}