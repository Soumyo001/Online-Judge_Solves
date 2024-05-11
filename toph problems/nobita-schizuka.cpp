#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        string s;cin>>s;
        int count=0;
        for(int j=0;j<s.length();j++){
            if(s[j]=='1'&&s[j+1]=='0'){
                 for(int k=j+1;k<s.length();k++){
                    if(s[k]=='1'){
                        count++;
                        break;
                    }
                 }
            }
        }
        cout<<"Case "<<i<<":"<<" "<<count<<endl;
    }
}