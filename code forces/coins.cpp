#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,s,c=0;cin>>n>>s;
    while(s){
        if(s-n>=0) {++c;s-=n;}
        else --n;
    }
    cout<<c<<endl;
}