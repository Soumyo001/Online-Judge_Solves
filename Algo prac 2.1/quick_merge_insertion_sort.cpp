#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+9;
//last element as pivot
int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(pivot>=arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
//first element as pivot
int partition01(int arr[],int l,int r){
    int pivot=arr[l];
    int i=l;
    for(int j=l+1;j<=r;j++){
        if(pivot>=arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[l]);
    return i;
}
void merge(int arr[],int l,int mid,int r){
    int n1=(mid-l+1);
    int n2=r-mid;
    int a1[n1+1],a2[n2+1];
    for(int i=0;i<n1;i++) a1[i]=arr[l+i];
    for(int i=0;i<n2;i++) a2[i]=arr[mid+1+i];
    a1[n1]=a2[n2]=inf;
    int i=0,j=0;
    for(int k=l;k<(l+n1+n2);k++){
        if(a1[i]<=a2[j]){
            arr[k]=a1[i];
            i++;
        }else{
            arr[k]=a2[j];
            j++;
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
void quickSort(int arr[],int l,int r){
    if(l<r){
        int par=partition(arr,l,r);
        quickSort(arr,l,par-1);
        quickSort(arr,par+1,r);
    }
}
void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void printArr(int* arr,int i,int size){
    if(i==size) return;
    printArr(arr+1,i+1,size);
    cout<<*arr<<" ";
}
int main(void){
    int arr[]={456,67,567,78,769,8,35,234,1234,1234};
    quickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    printArr(arr,0,sizeof(arr)/sizeof(arr[0]));cout<<endl;
    mergeSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    printArr(arr,0,sizeof(arr)/sizeof(arr[0]));cout<<endl;
    insertionSort(arr,sizeof(arr)/sizeof(arr[0]));
    printArr(arr,0,sizeof(arr)/sizeof(arr[0]));
}