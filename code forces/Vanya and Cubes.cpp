#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    int h=0,count=1,i=1,sum=1;
    while(sum<=n){
        h+=1;
        sum+=count+=i+=1;
    }
    cout<<h;
}