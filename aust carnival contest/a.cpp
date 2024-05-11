#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        string t=s;
        int k=0,l=0;
        //  for(int i=0;i<s.length();i++){
        //      for(int j=i+1;j<s.length();j++){
        //         if(s[i]==s[j]) s.erase(j,j);
        //      }
        //  }
        // int a=0,o=0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='o'||s[i]=='p'||s[i]=='e'||s[i]=='r'||s[i]=='a'||s[i]=='n'||s[i]=='d') o++;
        // }
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='a'||s[i]=='s'||s[i]=='e'||s[i]=='m'||s[i]=='b'||s[i]=='l'||s[i]=='r') a++;
        // }
        // if(a==7 || o==7){cout<<"Yes"<<endl;}
        // else cout<<"No"<<endl;
        string o="operand";
        string a="assembler";
        for(int i=0;i<s.length();i++){
            if(o.find(s[i])!=string::npos){k++;o.erase(o.find(s[i]),o.find(s[i])+1);}
            cout<<o<<endl;
        }
        for(int i=0;i<s.length();i++){
            if(a.find(s[i])!=string::npos) {l++;a.erase(a.find(s[i]),a.find(s[i])+1);}
        }
        cout<<l<<" "<<k<<endl;
        if(k==7 || l==9) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
//operand
//assembler