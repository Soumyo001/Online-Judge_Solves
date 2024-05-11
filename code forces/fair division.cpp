#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int one=0,two=0;
        int arr[n+10];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1) one++;
            else two++;
        }
        if(two%2==0 && one%2==0) cout<<"YES"<<endl;
        else if(one%2==0 && one>=2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}