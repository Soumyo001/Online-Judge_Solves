#include<bits/stdc++.h>
using namespace std;
int s(long long i){
    int c=0;
    while(i){
        if(i%10) c++;
        i/=10;
    }
    return c;
}
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        // if(n==1){
        //     cout<<0<<endl;continue;
        // }else if(n>1 && n<=10){
        //     cout<<1<<endl;continue;
        // }
        // int count=0;
        // for(int i=9;i<=n;i+=10){
        //     count++;
        // }
        // cout<<count<<endl;
        cout<<(n+1)/10<<endl;
    }
}