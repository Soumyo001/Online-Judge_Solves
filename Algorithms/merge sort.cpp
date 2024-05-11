#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+9;
void merge(int arr[],int l,int mid,int r){
    int n1=(mid-l)+1;
    int n2=r-mid;
    int a[n1+1],b[n2+1];
    for(int i=0;i<n1;i++) a[i]=arr[l+i];
    for(int i=0;i<n2;i++) b[i]=arr[mid+1+i];
    a[n1]=inf;
    b[n2]=inf;
    int i=0,j=0;
    for(int k=l;k<(n1+n2+l);k++){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            i+=1;
        }else{
            arr[k]=b[j];
            j+=1;
        }
    }
}
void mergesort(int a[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main(void){
    int a[]={19,7,5,3,16,2,9,8};
     mergesort(a,0,sizeof(a)/sizeof(a[0])-1);
     for(int i=0;i<sizeof(a)/sizeof(a[0]);i++) cout<<a[i]<<" ";
}