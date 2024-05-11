#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    string s;cin>>s;
    int count=0,d=0,u=0,l=0;
    for(int i=0;i<s.length();i++){
        if(s[i]-'0'>=65&&s[i]-'0'<=90) u=1;
        else if(s[i]-'0'>=97&&s[i]-'0'<=122) l=1;
        else if(s[i]-'0'>=48&&s[i]-'0'<=57) d=1;
        if(u&&l&&d){
            count++;
            d=u=l=0;
        }
    }
    cout<<count<<endl;
}