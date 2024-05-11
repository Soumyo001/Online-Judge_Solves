#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if(a%b==0) {cout<<0<<endl;continue;}
        cout<<(((a/b)+1)*b)-a<<endl;
    }
}