#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        set<char> c;
        int count = 0;
        for(int j=0;j<s.length();j++){
            c.insert(s[j]);
            if(c.size()>3){
                count++;
                c.clear();
                c.insert(s[j]);
            }
        }
        if(!c.empty()) count++;
        cout<<count<<endl;
    }
}
int main(void){
    int t=1;//cin>>t;
    while(t--) solve();
}
// 5/3=1 10/3=3