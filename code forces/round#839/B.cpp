#include<bits/stdc++.h>
#define cond a[0][0]<a[0][1] && a[0][0]<a[1][0] && a[1][0]<a[1][1] && a[0][1]<a[1][1]
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int a[4][4];
        int N=2,flag=1;
        for(int i=0;i<2;i++)for(int j=0;j<2;j++)cin>>a[i][j];
        if(a[0][0]<a[0][1] && a[0][0]<a[1][0] && a[1][0]<a[1][1] && a[0][1]<a[1][1]) {cout<<"YES"<<endl;continue;}
        for(int i=0;i<4;i++){
            for (int i = 0; i < N / 2; i++) {
            for (int j = i; j < N - i - 1; j++) {
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
            }
        }
          if(cond) {cout<<"YES"<<endl;flag=0;break;}
        }
        if(flag)cout<<"NO"<<endl;
    }
}