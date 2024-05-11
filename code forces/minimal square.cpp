#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if(a>=b){
            b+=b;
            if(b>a) cout<<b*b<<endl;
            else cout<<a*a<<endl;
        }else if(b>a){
            a+=a;
            if(a>b) cout<<a*a<<endl;
            else cout<<b*b<<endl;
        }
    }
}