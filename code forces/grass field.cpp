#include<bits/stdc++.h>
using namespace std;
void solve(){
    int all1=1,all0=1,one=0;
    vector<vector<int>> v(2,vector<int>());
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int n;cin>>n;if(n==0) all1=0;if(n==1) all0=0,one++;
            v[i].push_back(n);
        }
    }
    if(all1){
        cout<<2<<endl;return;
    }
    if(all0){
        cout<<0<<endl;return;
    }
    if(one==2 || one==1 || one==3){
        cout<<1<<endl;return;
    }
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}