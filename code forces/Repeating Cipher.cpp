#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    string s;cin>>s;
    if(s.length()==1){
        cout<<s<<endl;return 0;
    }
    int count=1;
    string ans="";
    for(int i=0;i<s.length();i+=count,++count) ans+=s[i];
    cout<<ans<<endl;
}