#include<bits/stdc++.h>
using namespace std;
string binary_search(int arr[],int l,int r,int k){
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==k) return "Found!";
        else if(arr[mid]>k) r=mid-1;
        else l=mid+1;
    }
    return "Not Found";
}
int main(void){
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++) cin>>arr[i];
    int key;cin>>key;
    cout<<binary_search(arr,0,n-1,key)<<endl;
}