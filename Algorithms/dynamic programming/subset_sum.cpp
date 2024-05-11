#include<bits/stdc++.h>
using namespace std;
vector<int> datas;
vector<int> subset;
int dp[100][100];
vector<vector<int>> subsets;
bool subset_sum(int sum,int i,int n){
    if(sum==0) {subsets.push_back(subset);return true;}
    if(i==n) return false;
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool isPossible=subset_sum(sum,i+1,n);
    subset.push_back(datas[i]);
    if(sum-datas[i]>=0) isPossible |= subset_sum(sum-datas[i],i+1,n);
    subset.pop_back();
    return dp[i][sum]=isPossible;
}
int main(void){
    memset(dp,-1,sizeof(dp));
    int n,value,tSum=0;cin>>n>>value;
    datas.resize(n+1);
    for(int i=0;i<n;i++) cin>>datas[i],tSum+=datas[i];
    if(value>tSum) return 0;
    if(tSum==value){
        cout<<1<<endl;
        return 0;
    }
    cout<<subset_sum(value,0,n)<<endl;
    for(auto subset:subsets){
        for(auto& i:subset) cout<<i<<" ";
        cout<<endl;
    }
}