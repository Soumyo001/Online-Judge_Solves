#include<bits/stdc++.h>
using namespace std;
string add(string a,string b)
{
    int sum=0,carry=0;
    string ans;
    if(a.length()<b.length())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<b.length();i++){
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        ans+=(sum%10+'0');
        carry=sum/10;
    }
    for(int i=b.length();i<a.length();i++){
        sum=(a[i]-'0')+carry;
        ans+=(sum%10+'0');
        carry=sum/10;
    }
    if(carry)
        ans+=(carry+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(void){
  int t;
  string a,b;
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>a>>b;
    printf("Case #%d: ",i);
    cout<<add(a,b)<<endl;
  }
}
