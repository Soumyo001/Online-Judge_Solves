//binary exponentiation is nothing but a simple power algorithm
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=1e18+7;
int binExprecurr(int a,int b){
    if (b == 0)
        return 1;
    int res = binExprecurr(a, b / 2);
    if (b & 1)
        return (a * (res * 1LL * res) % M) % M;
    else
        return (res * 1LL * res) % M;
}
//in case of overflow for M=1e18+7 or smtng...
int binMulti(ll a,ll b){
    int ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b = b >> 1;
    }
    return ans;
}
int binExpItr(int a,int b){
    int ans = 1;
    while (b>0)
    {
        if (b & 1)
        {
            ans = binMulti(ans,a);
        }
        a = binMulti(a,a);
        b = b >> 1;
    }
    return ans;
}
int bigmod(int base,int power,int mod){
    if (power == 0)
        return 1;
    else if (power & 1)
    {
        int a = base % mod;
        int b = (bigmod(base, power - 1, mod)) % mod;
        return (a *  1LL * b) % mod;
    }
    else
    {
        int a = (bigmod(base, power / 2, mod)) % mod;
        return (a * 1LL * a) % mod;
    }
}
int main(void){
    int a,b;
    while(cin>>a>>b)
    cout<<binExprecurr(a,b)<<" "<<binExpItr(a,b)<<" "<<endl;
}
//2374859,3029382