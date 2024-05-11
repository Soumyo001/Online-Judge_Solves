#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<int> graph[N];
deque<int> team;
vector<deque<int>> teams,two,one;
bool vis[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
void dfs(int vertex){
    vis[vertex]=true;
    team.push_back(vertex);
    for(auto& i:graph[vertex]) if(!vis[i]) dfs(i);
}
int main(void){
    cin>>n>>m;
    if(m==0 && n%3==0){
        for(int i=n;i>0;--i) cout<<i<<" ";cout<<endl;
        return 0;
    }else if(m==0 && n%3!=0){
        cout<<-1<<endl;return 0;
    }
    inputGraph();
    int tt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i] && !graph[i].empty()){
            team.clear();
            dfs(i);
            if(team.size()<=3 && team.size()>0){
                if(team.size()==2) ++tt;
                teams.push_back(team);
            }else if(team.size()>3){
                cout<<-1<<endl;
                exit(0);
            }
        }
    }
    team.clear();
    for(int i=n;i>=1;--i) if(!vis[i]) team.push_back(i);
    if(tt>team.size() || (team.size()-tt)%3!=0){
        cout<<-1<<endl;
        return 0;
    }
    for(auto& i:teams){
        reverse(i.begin(),i.end());
        if(i.size() == 2 && !team.empty() && tt){
            i.push_back(team.back());
            team.pop_back();
        }
        for(auto& j:i) cout<<j<<" ";cout<<endl;
    }
    if(!team.empty() && team.size()%3==0){
        reverse(team.begin(),team.end());
        int count=0;
        for(auto& i:team){
            ++count;
            cout<<i;
            if(count==3){
                cout<<"\n";count=0;
            }
            else cout<<" ";
        }
    }
}