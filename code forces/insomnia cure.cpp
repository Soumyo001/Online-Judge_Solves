#include<bits/stdc++.h>
using namespace std;
const int N=1e7+15;
vector<bool> prime(N,1);
void sieve(){
    prime[0]=false,prime[1]=false;
    for(int i=2;i<N;i++){
        if(prime[i]){
            for(int j=2*i;j<N;j+=i) prime[j]=false;
        }
    }
}
int main(void){
    //sieve();
    int k,l,m,n,d;cin>>k>>l>>m>>n>>d;
    if(k==1 || l==1 || m==1 || n==1){
        cout<<d<<endl;
        return 0;
    }
    if(k>d || l>d || m>d || n>d){
        cout<<0<<endl;return 0;
    }
    // prime[1]=true;
    // prime[k]=prime[l]=prime[m]=prime[n]=false;
    // cout<<count(prime.begin(),prime.begin()+d,0)<<endl;
    int arr[d+10];
    for(int i=0;i<=d;i++) arr[i]=1;
    for(int i=k;i<=d;i+=k) arr[i]=0;
    for(int i=l;i<=d;i+=l) arr[i]=0;
    for(int i=m;i<=d;i+=m) arr[i]=0;
    for(int i=n;i<=d;i+=n) arr[i]=0;
    cout<<count(arr+1,arr+d+1,0)<<endl;
}