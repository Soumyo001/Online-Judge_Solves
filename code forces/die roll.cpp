#include<bits/stdc++.h>
#define gcd(x,y) __gcd(x,y)
using namespace std;
int main(void){
    int a,b;cin>>a>>b;
    int c=(6-max(a,b)+1);
    cout<<to_string(c/gcd(c,6))<<"/"<<to_string(6/gcd(c,6));
}