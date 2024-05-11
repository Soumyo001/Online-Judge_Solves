#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define VLL vector<long long>
#define VS vector<string>
#define sf scanf
#define pf printf

int main()
{
    bool f=true; int i;
    string a,b; cin>>a>>b; int  x[26],y[26]; memset(x,0,26*sizeof(int)); memset(y,0,26*sizeof(int));

    for(i=0; i<a.length(); i++)
    {
        x[a.at(i)-'a']++;
    }
    for(i=0; i<b.length(); i++)
    {
        y[b.at(i)-'a']++;
    }
    for(i=0; i<26; i++) if(x[i]!=y[i]) {f=false; break;}
    if(f) cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
