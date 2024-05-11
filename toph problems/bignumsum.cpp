#include<bits/stdc++.h>
using namespace std;
string solve(){
    string a,b;
    cin>>a>>b;
    string ans="";
    int carry=0;
    for(int i=a.length()-1;i>=0;i--){
        int sum = (a[i]-'0')+(b[i]-'0')+carry;
        ans+= (sum%10)+'0';
        carry=sum/10;
    }
    if(carry) ans+=(carry+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(void){
    cout<<solve()<<endl;
}