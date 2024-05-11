#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N];
int dp[1005][1005];
vector<int>subset;
vector<vector<int>> subsets;
bool subsetSum(int idx,int sum,int n){
    if(sum==0) {subsets.push_back(subset); return true;}
    if(idx==n) return false;
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    bool isPossible=subsetSum(idx+1,sum,n);
    subset.push_back(arr[idx]);
    if(sum-arr[idx]>=0) isPossible |= subsetSum(idx+1,sum-arr[idx],n);
    subset.pop_back();
    return dp[idx][sum]=isPossible;
}
int main(void){
    memset(dp,-1,sizeof(dp));
    int n,sum;cin>>n>>sum;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<subsetSum(0,sum,n)<<endl;
    for(auto& i:subsets){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}