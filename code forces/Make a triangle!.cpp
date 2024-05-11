#include<bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c;cin>>a>>b>>c;
    int ans=0;
    int mx=max(a,max(b,c));
    if(mx==a){
        while(a>=b+c){
            ++ans;++b;
        }
    }else if(mx==b){
        while(b>=a+c){
            ++ans;++a;
        }
    }else{
        while(c>=a+b){
            ++ans;++a;
        }
    }
    cout<<ans<<endl;
}