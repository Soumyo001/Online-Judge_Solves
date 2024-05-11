#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
int status[N],n,m,level[N];
void inputGraph(){
    int i;
    for(i=n;i<=m;){
        graph[i].push_back(2*i);
        graph[2*i].push_back(i);
        if((i-1)>0){
            graph[i].push_back(i-1);
            graph[i-1].push_back(i);
        }
        status[i]=1;
    }
}
void bfs(int source){
    queue<int> q;
    q.push(source);
    status[source]=2;
    int val=0;
    while(val<=2*m && !q.empty()){
        val=q.front();q.pop();
        status[val]=3;
        if((val-1)>0 && status[val-1]==1){
            q.push(val-1);
            status[val-1]=2;
            level[val-1]=level[val]+1;
        }
        if(status[2*val]==1) {
            q.push(2*val);
            status[2*val]=2;
            level[2*val]=level[val]+1;
        }
    }
}
int main(void){
    cin>>n>>m;
    if(n>m){
        cout<<n-m<<endl;return 0;
    }else if(n==m){
        cout<<0<<endl;return 0;
    }
    //inputGraph();
    for(int i=1;i<=2*m;i++) status[i]=1;
    bfs(n);
    cout<<level[m]<<endl;
}