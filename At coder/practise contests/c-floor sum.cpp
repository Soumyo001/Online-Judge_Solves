#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        long long n,m,a,b;cin>>n>>m>>a>>b;
        double sum=0;
        for(int i=0;i<n;i++) sum+=((a*i+b)/m);
        cout<<floor(sum)<<endl;
    }
}