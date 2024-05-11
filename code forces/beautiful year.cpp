#include<bits/stdc++.h>
using namespace std;
bool distinct(int y){
    int ans[4],i=3;
    while(y){
        ans[i]=y%10;i--;
        y/=10;
    }
    for(int i=0;i<3;i++) for(int j=i+1;j<4;j++) if(ans[i]==ans[j]) return false;
    return true;
}
int main(void){
    int n;cin>>n;

    for(int i=n+1;i<=9999;i++){
        if(distinct(i)){
            cout<<i<<endl;
            break;
        }
    }
}