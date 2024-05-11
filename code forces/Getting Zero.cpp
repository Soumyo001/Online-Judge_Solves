#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
int status[N],level[N],arr[N];
int n;
void Clear(){
    for(int i=1;i<=N;i++){
        status[i]=1;level[i]=0;
    }
}
int bfs(int source){
    queue<int> q;
    q.push(source);
    status[source]=2;
    int count=(source%2==0 ? 0:15);
    while(!q.empty()){
        int val=q.front();q.pop();
        cout<<val%32768<<" ";
        status[val]=3;
        if(val%32768==0) return level[val];
        if(status[val*2]==1 && count!=15){
            ++count;
            q.push(val*2);
            status[val*2]=2;
            level[val*2]=level[val]+1;
        }
        if(status[val+1]==1 && count==15){
            q.push(val+1);
            status[val+1]=2;
            count=0;
            level[val+1]=level[val]+1;
        }
    }
    cout<<endl;
    return -1;
}
int main(void){
    cin>>n;
    int ans,count=0,flag=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        count=0,ans=INT_MAX;
        for(int k=0;k<15;k++){
            for(int x=0;x<15;x++){
                if(((arr[i]+k)*(1<<x))%(1<<15)==0){
                    ans=min(ans,x+k);
                }
            }
        }
        cout<<ans<<" ";
    }
}