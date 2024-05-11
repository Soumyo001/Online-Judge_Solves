#include<bits/stdc++.h>
using namespace std;
void __insertion_sort(int arr[],int l,int r){
    for(int i=l+1;i<=r;i++){
        int curr=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>curr){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
    }
}
void __merge_insertion_combined_sort(int arr[],int l,int r){
    if((r-l)>=8){
        int mid=(l+r)/2;
        __merge_insertion_combined_sort(arr,l,mid);
        __merge_insertion_combined_sort(arr,mid+1,r);
        __insertion_sort(arr,l,r);
    }
}
int main(void){
    int arr[]={435,324,324,324,65,5,6765,7,658,8679,789,7,453,32,4,4332,42,35,436,467,6,8867,998707,8,46,435,435,324,324,32,432,5,7,658,679,9870,79,0,7,56,43,234,21,321,31,24342,3,42,543,34,6547,567,876867,987,987,9870,809,98,80,4675,456,654,543,34,5,435,24,324,23,41,43,123,123,213,4,453};
    int n=sizeof(arr)/sizeof(arr[0]);
    __merge_insertion_combined_sort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}