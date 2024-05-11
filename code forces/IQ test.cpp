#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,cte=0,cto=0,ide,ido;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x&1){
            cto++;ido=i;
        }else{
            cte++;ide=i;
        }
    }
    cout<<(cte==1 ? ide :ido);
    cout<<endl;
}