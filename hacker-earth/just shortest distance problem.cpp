#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<int>graph[N];
vector<int> dist(N,INT_MAX);
int n,m;
void bfs(int source){
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int val=q.front();q.pop();
        if(dist[val]>=INT_MAX) continue;
        for(auto& i:graph[val]){
            if(dist[val]+1<dist[i]){
                q.push(i);
                dist[i]=dist[val]+1;
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    dist[1]=0;
    while(m--){
        int a;cin>>a;
        if(a==1){
            int k;cin>>k;
            cout<<(dist[k]>=INT_MAX?-1:dist[k])<<endl;
        }else if(a==2) {
            int a, b;
            cin >> a >> b;
            if (a == b) continue;
            graph[a].push_back(b);
            bfs(a);
        }
    }
}