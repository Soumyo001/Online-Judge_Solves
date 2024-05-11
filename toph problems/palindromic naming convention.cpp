#include<bits/stdc++.h>
using namespace std;
int solve(){
    string s;cin>>s;
    if(s.length()==1){
        cout<<s<<" "<<s<<endl;
        return 0;
    }
    for(int i=1;i<s.size();i++)
    {
        if([&](int i,int j)->bool{
            while(i<j){
                if(s[i]==s[j]){
                    i++;j--;
                }else return false;
            }
            return true;
        }(i,s.size()-1)){
            string ss;
            ss=s.substr(0,i);
            reverse(ss.begin(),ss.end());
            cout<<s<<" "<<ss<<endl;
            return 0;
        }
    }
    
}
int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;i++) solve();
}