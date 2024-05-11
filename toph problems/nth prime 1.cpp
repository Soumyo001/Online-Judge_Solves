#include<bits/stdc++.h>
using namespace std;
int prime(int x){
    if(x<=1) return false;
    if(x<=3) return true;
    if(x%2==0||x%3==0) return false;
for(int i=5;i*i<=x;i+=6){
    if(x%i==0||x%(i+2)==0) return false;
}
        return true;
}
int main(){
int n;
cin>>n;
int c=2,l=0;
while(1){
    if(prime(c)==true)
        l++;
    if(l==n){
        cout<<c<<endl;
        break;
    }
    c++;
}
return 0;
}
