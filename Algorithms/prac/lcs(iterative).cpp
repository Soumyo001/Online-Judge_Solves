#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
void printLCS(vector<vector<int>>& b,string x,int i,int j){
    if(i==0 || j==0) return;
    if(b[i][j]==1){
        printLCS(b,x,i-1,j-1);
        cout<<x[i-1];
    }else if(b[i][j]==2) printLCS(b,x,i-1,j);
    else printLCS(b,x,i,j-1);
}
void solve(string& s1,string& s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> c(n+1,vector<int>(m+1));
    vector<vector<int>> b(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) c[i][0]=0;
    for(int i=0;i<=m;i++) c[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }else{
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    }
    cout<<c[n][m]<<endl;
    printLCS(b,s1,n,m);
}
int main(void){
    string s1,s2;cin>>s1>>s2;
    solve(s1,s2);
}