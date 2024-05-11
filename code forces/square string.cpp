#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        if(s.length()%2!=0) {
            cout<<"NO"<<endl;continue;
        }
        int flag=1;
        for(int i=(s.length()/2)-1,j=s.length()-1;i>=0,j>=s.length()/2;i--,j--) if(s[i]!=s[j]) flag=0;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}