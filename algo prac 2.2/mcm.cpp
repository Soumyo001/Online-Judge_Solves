#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Matrix{
    int row,col;
};
long long dp[1005][10005];
vector<Matrix> matrix;

long long mcm(int i,int j){
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    long long ans = LLONG_MAX;
    for(int k = i; k < j; k++){
        ans = min(ans, mcm(i,k) + mcm(k+1,j) + (matrix[i].row * matrix[k].col * matrix[j].col));
    }
    return dp[i][j] = ans;
}

int main(void){
    memset(dp, -1 ,sizeof(dp));
    int n;cin>>n;
    matrix.resize(n+1);
    for(int i=0;i<n;i++) cin>>matrix[i].row>>matrix[i].col;
    cout<<mcm(0,n-1)<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}