#include<bits/stdc++.h>
using namespace std;
void solve(){
    char c;int row;cin>>c>>row;
    for(int i=1;i<=8;i++){
        if(i==row) continue;
        cout<<c<<i<<endl;
    }
    for(char i='a';i<='h';i++){
        if(i==c) continue;
        cout<<i<<row<<endl;
    }
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}