#include<bits/stdc++.h>
using namespace std;
int dp[105][10005];
string s1,s2;
int lcs(int i, int j){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = lcs(i-1,j);
    ans = max(ans, lcs(i,j-1));
    ans = max(ans, lcs(i-1,j-1) + (s1[i] == s2[j]));
    return dp[i][j] = ans;
}
int main(void){
    memset(dp, -1, sizeof(dp));
    cin>>s1>>s2;
    cout<<lcs(s1.length()-1,s2.length()-1)<<endl;
}