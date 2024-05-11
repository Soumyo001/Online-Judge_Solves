#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int wt[N],val[N];
long long dp[1005][1005];
vector<int>value;
vector<int> weight;
vector<vector<int>> values;
vector<vector<int>> weights;
long long knapsack(int idx,int wt_left){
    if(wt_left==0){values.push_back(value);weights.push_back(weight);return 0;}
    if(idx<0) return 0;
    if(dp[idx][wt_left]!=-1) return dp[idx][wt_left];
    long long ans=knapsack(idx-1,wt_left);
    value.push_back(val[idx]);
    weight.push_back(wt[idx]);
    if(wt_left-wt[idx]>=0) ans=max(ans,knapsack(idx-1,wt_left-wt[idx])+val[idx]);
    value.pop_back();
    weight.pop_back();
    return dp[idx][wt_left]=ans;
}

int main(void){
    memset(dp,-1,sizeof(dp));
    int n,w;cin>>n>>w;
    for(int i=0;i<n;i++) cin>>wt[i]>>val[i];
    cout<<knapsack(n-1,w)<<endl;
    for(int i=0;i<values.size();i++){
        for(int j=0;j<values[i].size();j++){
            cout<<weights[i][j]<<" "<<values[i][j]<<endl;
        }
        cout<<endl;
    }
}
/*4 8
3 30
4 50
5 60
4 40*/