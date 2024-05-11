#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin()+1,v.end());
    for(int i=1;i<n;i++){
        if(v[0]<v[i]) {
            if((v[i]-v[0])%2){
                v[0]+=((v[i]-v[0])/2)+1;
            }else v[0]+=((v[i]-v[0])/2);
        }
    }
    cout<<v[0]<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}