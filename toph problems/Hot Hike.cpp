#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    int arr[201];
    for(int i=0;i<n;i++) cin>>arr[i];
    int maxim=300,max=0,d;
    for(int i=0;i<n-2;i++){
        if(arr[i]<arr[i+2]) max=arr[i+2];
        else max=arr[i];
        if(max<maxim){
            maxim=max;
            d=i;
        }
    }
    cout<<d<<" "<<maxim<<endl;
}