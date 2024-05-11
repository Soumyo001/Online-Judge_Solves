#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int wt[N],val[N];
long long dp[1005][1005];
vector<int>value;
vector<int> weight;
vector<vector<int>> values;
vector<vector<int>> weights;
long long knapsack(int idx,int val_left){
    if(val_left==0) {weights.push_back(weight);values.push_back(value); return 0;}
    if(idx<0) return 1e15;
    if(dp[idx][val_left]!=-1) return dp[idx][val_left];
    long long ans=knapsack(idx-1,val_left);
    value.push_back(val[idx]);
    weight.push_back(wt[idx]);
    if(val_left-val[idx]>=0) ans=min(ans,knapsack(idx-1,val_left-val[idx])+wt[idx]);
    value.pop_back();
    weight.pop_back();
    return dp[idx][val_left]=ans;

}
int main(void){
    memset(dp,-1,sizeof(dp));
    int n,w;cin>>n>>w;
    for(int i=0;i<n;i++) cin>>wt[i]>>val[i];
    for(int i=1e3;i>=0;i--){
        if(knapsack(n-1,i)<=w){
            cout<<i<<endl;
            break;
        }
    }
    for(int i=0;i<values.size();i++){
        for(int j=0;j<values[i].size();i++){
            cout<<weights[i][j]<<" "<<values[i][j]<<endl;
        }
    }
}