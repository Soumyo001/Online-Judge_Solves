#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10];
int dist[10];
bool vis[10];
void clear(){
    for(int i=0;i<10;i++){
        vis[i]=false;
        dist[i]=0;
    }
}
void inputGraph(){
    for(int i=1;i<=4;i++){
        char a,b,c,d;cin>>a>>b>>c>>d;
        if(c=='>') graph[a-'A'+1].push_back(d-'A'+1);
        else graph[d-'A'+1].push_back(a-'A'+1);
    }
}
bool dfs(int start,int end){
   vis[start]=true;
   bool b=false;
   for(auto& i:graph[start]){
    if(i==end) return true;
    if(vis[i]) continue;
    b|=dfs(i,end);
   }
   return b;
}
int main(void){
    inputGraph();
    int q;cin>>q;
    while(q--){
        clear();
        char a,b;cin>>a>>b;
        //if(a==b) {cout<<"NO"<<endl;continue;}
        if(dfs(a-'A'+1,b-'A'+1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}