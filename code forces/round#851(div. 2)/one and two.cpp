#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++) cin>>arr[i];
        long long sum=0,k=0,s=0;
        for(int i=0;i<(n-1);i++){
            sum+=arr[i];
            for(int j=i+1;j<n;j++){
                s+=arr[j];
            }
            if(sum==s){
                k=i;break;
            }
            s=0;
        }
        if(k==0) cout<<-1<<endl;
        else cout<<k<<endl;
    }
}