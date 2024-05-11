#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e18;
int main(void){
    ll n;cin>>n;
    int count=0;
    while(n!=0){
        if(n%10==4 || n%10==7) count++;
        if(count>7){
            cout<<"NO"<<endl;return 0;
        }
        n=n/10;
    }
    if(count==4 || count==7){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}