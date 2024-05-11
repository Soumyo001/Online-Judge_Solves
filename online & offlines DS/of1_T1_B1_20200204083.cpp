#include<bits/stdc++.h>
using namespace std;
int main(void){
    string s1,s2;
    getline(cin,s1);
    cin>>s2;
    int j=0;
    for(int i=0;i<s1.length();i++){
          if(s2[0]==s1[i]){
              for(j=0;j<s2.length();j++){
                    if(s2[j]==s1[i+j]){
                        continue;
                    }else {
                        break;
                    }
              }
          }
          if(j==s2.length()) {
              cout<<"Found"<<endl;
              break;
          }
    }
    if(j!=s2.length()) cout<<"Not found"<<endl;
}