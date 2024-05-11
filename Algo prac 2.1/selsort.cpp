#include<bits/stdc++.h>
using namespace std;
void selSort(int arr[],int size){
    for(int i=0;i<(size-1);i++){
        int min=i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[min]>arr[j]) min=j;
        }
        swap(arr[i],arr[min]);
    }
}
void printArr(int* arr,int i,int size){
    if(i==size) return;
    cout<<*arr<<" ";
    printArr(arr+1,i+1,size);
}
int main(void){
    int arr[]={45,657,67,768,32,4,23,2,4,131,341,23,3245};
    selSort(arr,sizeof(arr)/sizeof(arr[0]));
    printArr(arr,0,sizeof(arr)/sizeof(arr[0]));
}