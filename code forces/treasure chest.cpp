#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int x,y,z;cin>>x>>y>>z;
        if(x>y || x==y){
            cout<<x<<endl;continue;
        }else if(x<y && z>=(y-x)){
            cout<<y<<endl;continue;
        }
        cout<<x+z+(y-(x+z))*2<<endl;
    }
}