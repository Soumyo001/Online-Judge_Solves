#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b&&a>c) cout<<"Case "<<i<<":"<<" A"<<endl;
        else if(b>a&&b>c) cout<<"Case "<<i<<":"<<" B"<<endl;
        else if(c>b&&c>a) cout<<"Case "<<i<<":"<<" C"<<endl;
        else cout<<"Case "<<i<<":"<<" Confused"<<endl;
    }
}
