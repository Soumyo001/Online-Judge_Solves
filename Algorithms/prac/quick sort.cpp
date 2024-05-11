#include<bits/stdc++.h>
using namespace std;
// //last as pivot
// int partition(int arr[],int l,int r){
//     int pivot=arr[r];
//     int i=l-1;
//     for(int j=l;j<r;j++){
//         if(arr[j]<pivot){
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }
//     swap(arr[i+1],arr[r]);
//     return i+1;
// }
// //first element as pivot
// int partition(int arr[],int l,int r){
//     int pivot=arr[l],i=l;
//     for(int j=l+1;j<=r;j++){
//         if(arr[j]<pivot){
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }
//     swap(arr[i],arr[l]);
//     return i;
// }
//mid element as pivot
int partition(int arr[],int l,int r){
    int midPos=(l+r)/2;
    int pivot=arr[midPos];
    int i=l-1;
    for(int j=l;j<midPos;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    int temp=i;
    swap(arr[i],arr[midPos]);
    for(int j=midPos+1;j<=r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[temp],arr[i]);
    return i;
}
//random element as pivot
int partition01(int arr[],int l,int r,int pNum){
    pNum=l+pNum-1;
    int pivot=arr[pNum];
    int i=l-1;
    for(int j=l;j<pNum;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;int temp=i;
    swap(arr[i],arr[pNum]);
    for(int j=pNum+1;j<=r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[temp]);
    return i;
}
void quickSort(int arr[],int l,int r,int pNum=2){
    if(l<r){
        int p=partition01(arr,l,r,pNum);
        quickSort(arr,l,p-1);    
        quickSort(arr,p+1,r);    
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
int main(void){
    int arr[]={1,2,43,56,78,1123,23,23,23,23,23,23,23,23,23,2,3,23,23,23,23,23,23,2,32,3,23,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,23,23,23,23,23,23,23,2,32,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,2323,10000,23,23,23,23,2,323,23,23,
    23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,2,2,2,22,2,2,2,2,2,2,2,2,2,2,2,2,22,2,2,2,2,2,2,2,22,2,2,2,2,22,2,2,2,2,2,2,2,2,2,2,2,2,2,2,22,2,2,2,22,22,2,2,22,
    23,2,323,2,32,32,32,323,23,23,23,23,23,23,23,23,232,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,2,32,32,32,323,23,23,23,23,23,23,23,23,23,23,23,23,
    23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,322,33,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,22,2,2,2,2,2,22,2,2,22,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,223,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,213,23,23,23,23,23,23,23,23,23,23,23,23,23,23,2,323,23,23,23,23,23};
    quickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    print(arr,sizeof(arr)/sizeof(arr[0]));
}