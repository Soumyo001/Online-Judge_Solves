#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    int max=0;
    int a[5000];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        if(max<a[i]) max=a[i];
    }
    cout<<max<<endl;
}