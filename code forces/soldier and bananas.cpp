#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k,w;
    cin>>k>>n>>w;
    long long sum=0;
    for(int i=1;i<=w;i++){
        sum+=(i*k);
    }
    cout<<((sum-n)<=0 ? 0 : (sum-n));
    cout<<endl;
}