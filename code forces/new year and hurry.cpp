#include<bits/stdc++.h>
using namespace std;
int main(void){
    int tot=240;
    int n,k;cin>>n>>k;
    tot-=k;
    if(tot==0) {
        cout<<0<<endl;return 0;
    }
    int cnt=0,i=1;
    while(i<=n){
        cnt+=(i*5);
        if(cnt>tot) break;
        i++;
    }
    i--;
    cout<<i<<endl;
}