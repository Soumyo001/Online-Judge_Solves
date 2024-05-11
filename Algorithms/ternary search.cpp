#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n){
    int j=0;
    for(int i=1;i<n;i++){
        int key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
string ternary_search(int arr[],int l,int r,int key){
    while(l<=r){
        int m1=l+((r-l)/3);
        int m2=r-((r-l)/3);
        if(arr[m1]==key || arr[m2]==key) return "Found!";
        if(arr[m1]>key) r=m1-1;
        else if(arr[m2]<key) l=m2+1;
        else{
            l=m1+1;
            r=m2-1;
        }
    }
    return "Not Found";
}
int main(void){
    int arr[1000];
    int n,key;cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    insertion_sort(arr,n);
    cin>>key;
    cout<<ternary_search(arr,0,n-1,key)<<endl;
}