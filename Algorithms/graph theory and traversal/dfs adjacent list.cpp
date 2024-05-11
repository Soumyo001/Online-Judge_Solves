#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>graph[N];
int vis[N],dist[N],status[N];
void inputGraph(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        int n,m;cin>>n>>m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
}
void initiStatus(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++) status[i]=1;
}
void dfs01(int source){
    cout<<source<<" ";
    vis[source]=1;
    for(const auto& i:graph[source]){
        if(vis[i]) continue;
        dfs01(i);
    }
}
void dfs(int source,int number_of_nodes){
    initiStatus(number_of_nodes);
    stack<int>st;
    st.push(source);
    status[source]=2;
    while(!st.empty()){
        int val=st.top();st.pop();
        status[val]=3;//ans remains same even if comment out this line
        cout<<val<<" ";
        for(const auto& i:graph[val]){
            if(status[i]==1){
                st.push(i);
                status[i]=2;
                //dist[i]=dist[val]+1;
            }
        }
    }
    cout<<endl;
}
void printDist(int number_of_nodes){
    for(int i=1;i<=number_of_nodes;i++){
        cout<<"Level of "<<i<<" is "<<dist[i]<<endl;
    }
}
int main(void){
    int n,m,s;cin>>n>>m>>s;
    inputGraph(n);
    dfs01(s);cout<<endl;
    dfs(s,n);
    //printDist(n);
}