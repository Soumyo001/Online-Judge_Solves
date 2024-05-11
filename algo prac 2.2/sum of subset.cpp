#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[1005][10005],value[N];
vector<vector<int>> subsets;
vector<int> subset;
bool subsetSum(int idx,int sum, int n){
    if(sum == 0) {subsets.push_back(subset); return true;}
    if(idx == n) return false;
    if(dp[idx][sum] != -1) return dp[idx][sum];
    bool isSum = subsetSum(idx + 1, sum, n);
    subset.push_back(value[idx]);
    isSum |= subsetSum(idx+1, sum - value[idx], n);
    subset.pop_back();
    return dp[idx][sum] = isSum;
}
int main(void){
    memset(dp, -1 , sizeof(dp));
    int n, sum;cin>>n>>sum;
    for(int i=0;i<n;i++) cin>>value[i];
    cout<<subsetSum(0, sum, n)<<endl;
    for(auto& subset: subsets){
        for(auto& i: subset) cout<<i<<" ";
        cout<<endl;
    }
}