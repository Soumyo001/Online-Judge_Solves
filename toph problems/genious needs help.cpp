/*#include<bits/stdc++.h>
using namespace std;
string add(string a,string b){
    string ans;
    int carry=0,sum=0;
    if(a.length()<b.length())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<b.length();i++){
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        ans+=(sum%10+'0');
        carry=sum/10;
    }
    for(int j=b.length();j<a.length();j++){
        sum=(a[j]-'0')+carry;
        ans+=(sum%10+'0');
        carry=sum/10;
    }
    if(carry)
        ans+=(carry+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(void){
    string a,b,ans;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a>>b;
        printf("Case #%d: ",i);
        cout<<add(a,b)<<endl;
    }
}*/
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t,i=1;
    scanf("%d",&t);
    while(i<=t){
    string a,b,ans;
    int carry=0,sum=0;
    cin>>a>>b;
    if(a.length()<b.length())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<a.length();i++){
        if(i<b.length()){
        sum=(a[i]-'0')+(b[i]-'0')+carry;
        ans+=(sum%10+'0');
        carry=sum/10;}
        else{
        sum=(a[i]-'0')+carry;
        ans+=(sum%10+'0');
        carry=sum/10;
        }
    }
    if(carry)
        ans+=(carry+'0');
    reverse(ans.begin(),ans.end());
    printf("Case #%d: ",i);
    cout<<ans<<endl;
    i++;
}
}
