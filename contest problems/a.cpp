#include<bits/stdc++.h>
using namespace std;
int main(void){
    string s;cin>>s;
    int c=0;
    if(s.length()==1) {cout<<0;return 0;}
    for(int i=0,j=s.length()-1;i<s.length()/2,j>=s.length()/2;i++,j--) if(s[i]!=s[j]) c++;
    cout<<c;
}