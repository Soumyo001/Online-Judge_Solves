#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    char arr[n][m];
    int flag=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {cin>>arr[i][j];if(arr[i][j]=='C' || arr[i][j]=='M' || arr[i][j]=='Y') flag=1;}
    //for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(arr[i][j]=='C' || arr[i][j]=='M' || arr[i][j]=='Y'){cout<<"#Color"<<endl;return 0;}
    if(flag) cout<<"#Color"<<endl;
    else cout<<"#Black&White"<<endl;
}