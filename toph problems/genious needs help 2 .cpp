#include<bits/stdc++.h>
#define PI 3.1415926535897932384626433832795
#define ll long long
#define sf scanf
#define pf printf
#define MOD 1000000007
#define debug(x) cout<<"---------"<<x<<endl;
#define LEN(a) sizeof(a)/sizeof(a[0])
#define MEM(arr,k) memset(arr,k,sizeof arr)
#define input freopen("01input","r",stdin)
#define output freopen("01output","w",stdout)
#define allset ios_base::sync_with_stdio(false);cin.tie(NULL)

int X8[] = {0, 1, 0, -1, 1, -1, 1, -1};
int Y8[] = {1, 0, -1, 0, 1, -1, -1, 1};
int X4[] = {1,-1, 0, 0};
int Y4[] = {0, 0, 1,-1};

using namespace std;

string solve (string s1,string s2){

    if (s1.length()>s2.length()) {
        swap(s1,s2);
    }
    string ans;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int carry=0,sum=0;
    for(int i=0;i<s1.length();i++){
        sum = (s1[i]-'0')+(s2[i]-'0')+carry;
        ans+=(sum%10 + '0');
        carry = sum/10;
    }
    for(int i = s1.length(); i<s2.length(); i++){
        int sum = (s2[i]-'0')+carry;
        ans+=(sum%10 + '0');
        carry = sum/10;
    }
    if(carry)
        ans+=(carry+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{

    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; cs++){
        string frst,scnd;
        cin>>frst>>scnd;
        printf("Case #%d: ",cs);
        cout<<solve(frst,scnd)<<endl;
    }
    return 0;
}
