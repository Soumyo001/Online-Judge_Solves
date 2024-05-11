#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int n1=(mid-l)+1;
    int n2=(r-mid);
    int a[n1+1],b[n2+1];
    for(int i=0;i<n1;i++) a[i]=arr[l+i];
    for(int i=0;i<n2;i++) b[i]=arr[mid+1+i];
    a[n1]=INT_MAX;
    b[n2]=INT_MAX;
    int i=0,j=0;
    for(int k=l;k<(n1+n2+l);k++){
        if(a[i]<=b[j]){
            arr[k]=a[i];i++;
        }else{
            arr[k]=b[j];j++;
        }
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
int main(void){
    int arr[]={4,7,23,43,23,3,357,687,5678,542,4,341,23,5235,132,554};
    mergeSort(arr,0,sizeof(arr)/sizeof(arr[0]));
    print(arr,sizeof(arr)/sizeof(arr[0]));
}