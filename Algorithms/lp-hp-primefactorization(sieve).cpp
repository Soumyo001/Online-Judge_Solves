#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<bool>is_prime(N,1);
vector<int>lp(N,0),hp(N,0);
void sieve(){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<N;i++){
        if(is_prime[i]){
            lp[i]=hp[i]=i;
            for(int j=i*2;j<N;j+=i){
                is_prime[j]=false;
                hp[j]=i;
                if(lp[j]==0) lp[j]=i;
            }
        }
    }
}
void prime_factors(int n){
    list<int> l;
    while(n>1){
        int prime_factor=hp[n];
        while(n%prime_factor==0){
            n/=prime_factor;
            l.push_back(prime_factor);
        }
    }
    for(auto& i:l) cout<<i<<" ";
}
int main(void){
    sieve();
    //for(int i=1;i<=100;i++) cout<<i<<" "<<is_prime[i]<<" "<<lp[i]<<" "<<hp[i]<<endl;
    prime_factors(84);
}
