#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m=INT_MIN;cin>>n;
        int a[n+10],count=0;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            count=0;
            for(int j=0;j<n;j++){
                if(a[i]==a[j]) count++;
            }
            m=max(m,count);
        }
        cout<<n-m<<endl;
    }
}