#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int lcs(int i,int j,string& s1,string& s2){
    // if(i==s1.length() || j==s2.length()) return 0;
    // if(dp[i][j]!=-1) return dp[i][j];
    // int ans=lcs(i+1,j,s1,s2);
    // ans=max(ans,lcs(i,j+1,s1,s2));
    // ans=max(ans,lcs(i+1,j+1,s1,s2)+(s1[i]==s2[j]));
    // return dp[i][j]=ans;
    if(i==s1.length() || j==s2.length()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return max(max(lcs(i+1,j,s1,s2),lcs(i,j+1,s1,s2)),lcs(i+1,j+1,s1,s2)+(s1[i]==s2[j]));
}
int main(void){
    memset(dp,-1,sizeof(dp));
    string s1,s2;cin>>s1>>s2;
    cout<<lcs(0,0,s1,s2);
}