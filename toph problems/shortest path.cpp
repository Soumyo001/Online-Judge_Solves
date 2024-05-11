#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
int status[N];
queue<int>q;
void inputGraph(int number_of_edges){
    for(int i=1;i<=number_of_edges;i++){
        int n,m;cin>>n>>m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
}
void initiStatus(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        status[i]=1;
    }
}
vector<int> bfs(int source,int number_of_nodes){
    initiStatus(number_of_nodes);
    vector<int> level(number_of_nodes,0);
    q.push(source);
    status[source]=2;
    while(!q.empty()){
        int val=q.front();q.pop();
        status[val]=3;
        for(const auto& it:graph[val]){
            if(status[it]==1){
                q.push(it);
                status[it]=2;
                level[it]=level[val]+1;
            }
        }
    }
    return level;
}
int main(void){
    int n,m,p;cin>>n>>m>>p;
    inputGraph(m);
    int s,t;
    cin>>s>>t;
    vector<int>a,b;
    a=bfs(s,n);
    int sc=a[t];
    b=bfs(t,n);
    initiStatus(n);
    for(int i=1;i<=n;i++) if(a[i]+b[i]==sc) {q.push(i);status[i]=2;}
    vector<int> c(n+1,0);
    while(!q.empty()){
        int val=q.front();q.pop();
        status[val]=3;
        for(const auto& it:graph[val]){
            if(status[it]==1){
                q.push(it);
                status[it]=2;
                c[it]=c[val]+1;
            }
        }
    }
    while(p--){
        int x;cin>>x;
        cout<<c[x]<<endl;
    }
}