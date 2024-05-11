#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    string s;cin>>s;
    int l=0,o=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L') ++l;
        else ++o;
    }
    l=o=0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='L') ++l;
        else ++o;
        int l1=0,o1=0;
        for(int j=i+1;j<n;j++){
            if(s[j]=='L') ++l1;
            else ++o1;
        }
        if(l!=l1 && o!=o1){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}