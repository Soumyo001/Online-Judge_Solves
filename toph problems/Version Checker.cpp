#include<bits/stdc++.h>
using namespace std;
int main(void){
    string s,s1;
    cin>>s>>s1;
    vector<int> v1,v2;int p=0;
    for(char c:s){
        if(c=='.'){v1.push_back(p);p=0;}
        else p=p*10+(c-'0');
    }
    v1.push_back(p);p=0;
    for(char c:s1){
        if(c=='.'){v2.push_back(p);p=0;}
        else p=p*10+(c-'0');
    }
    v2.push_back(p);p=0;
    if(v1>v2) cout<<s<<endl;
    else if(v2>v1) cout<<s1<<endl;

}
