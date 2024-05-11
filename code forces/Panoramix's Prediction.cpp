#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
vector<bool> prime(N,1);
void sieve(){
    prime[0]=prime[1]=false;
    for(int i=2;i<N;i++){
        if(prime[i]){
            for(int j=i*2;j<N;j+=i) prime[j]=false;
        }
    }
}
int main(void){
    sieve();
    int n,m;cin>>n>>m;
    int i;
    for(i=n+1;i<=m;i++)
        if(prime[i]) break;
    if(i==m) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}