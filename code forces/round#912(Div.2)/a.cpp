#include<bits/stdc++.h>
using namespace std;
void swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
void solve(){
    int n,k;cin>>n>>k;
    vector<int> arr(n,0);
    vector<int> temp(n,0);
    int sorted=1,rev_sorted=1,same=1;
    for(int i=0;i<n;i++) {cin>>arr[i];temp[i]=arr[i];if(i>0 && arr[i]<arr[i-1]) sorted=0;if(i>0 && arr[i]>arr[i-1]) rev_sorted=0;if(i>0 && arr[i]!=arr[i-1]) same=0;}
    if(sorted || (rev_sorted && n==k) || same || (k==1 && is_sorted(arr.begin(),arr.end())) || (n==1 && k==1)){
        cout<<"YES"<<endl;return;
    }else if(k==1){
        cout<<"NO"<<endl;return;
    }else{
        cout<<"YES"<<endl;return;
    }
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}