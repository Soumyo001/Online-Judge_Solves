#include<bits/stdc++.h>
#define gcd(x,y) __gcd(x,y)
using namespace std;
const int N=4e5+10;
vector<int>graph[N];
int status[N],a[N],level[N],parent[N];
int n;
void inputGraph(){
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(gcd(a[i],a[j])!=1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }    
}
void bfs(int source){
    for(int i=1;i<=n;i++) status[i]=1;
    queue<int>q;
    q.push(source);
    parent[source]=0;
    status[source]=2;
    while(!q.empty()){
        int val=q.front();
        q.pop();
        status[val]=3;
        for(auto& i:graph[val]){
            if(status[i]==1){
                parent[i]=val;
                q.push(i);
                status[i]=2;
                level[i]=level[val]+1;
            }
        }
    }
}
vector<int> lca(int s,int t){
    vector<int> lca;
    int par=t;
    while(par!=parent[s]){
        lca.push_back(par);
        par=parent[par];
    }
    //reverse(lca.begin(),lca.end());
    return lca;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    inputGraph();
    int s,t;cin>>s>>t;
    if(s==t){
        cout<<1<<endl<<s<<endl;
        return 0;
    }
    bfs(s);
    if(level[t]==0){cout<<-1<<endl;return 0;}
    vector<int> id=lca(s,t);
    reverse(id.begin(),id.end());
    cout<<level[t]+1<<endl;
    for(auto& it:id) cout<<it<<" ";
    cout<<endl;
}