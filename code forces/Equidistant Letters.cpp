#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;cin>>s;
    if(s.length()==2){
        cout<<s<<endl;return;
    }
    for(int i=0;i<s.length()-1;i++){
        char c=s[i];
        for(int j=i+1;j<s.length();j++){
            if(s[j]==c){
                swap(s[i+1],s[j]);
            }
        }
    }
    cout<<s<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}