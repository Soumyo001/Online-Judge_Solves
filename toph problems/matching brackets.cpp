#include<bits/stdc++.h>
using namespace std;
int main(void){
 string s;
 int a=1,n=0;
 stack<char>st;
 cin>>s;
 for(int i=0;i<s.length();i++){
    if(s[i]=='('||s[i]=='{'||s[i]=='['){
        st.push(s[i]);
        n++;
       }
    else{
        char ch=st.top();
        st.pop();
        if(s[i]==')')
          if(ch!='('){
            a=0;
            break;
           }
        if(s[i]=='}')
            if(ch!='{'){
                a=0;
                break;
            }
        if(s[i]==']')
        if(ch!='['){
            a=0;
            break;
        }
    }
 }
   if(n==s.length())
      a=0;
   if(a)
    cout<<"Yes"<<endl;
   else
    cout<<"No"<<endl;
}
