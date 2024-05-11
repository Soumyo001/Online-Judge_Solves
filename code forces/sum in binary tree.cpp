#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        long long sum=0;
        while(n!=1) sum+=n,n/=2;
        cout<<sum+1<<endl;
    }
}