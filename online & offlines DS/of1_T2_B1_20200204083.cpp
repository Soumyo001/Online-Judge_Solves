#include<bits/stdc++.h>
using namespace std;
void doSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                 int n=arr[j];
                 arr[j]=arr[i];
                 arr[i]=n;
            }
        }
    }
}
bool binSer(int a[],int lo, int Hi, int key)
{
    while(lo<=Hi)
    {
        int mid =(lo+Hi)/2;
        if(key==a[mid])
            return true;
        else if(key>a[mid])
            lo=mid+1;
        else if(key<a[mid])
            Hi=mid-1;
    }
    return false;
}

int main()
{
    int arr[] = {93, 87, 81, 37, 30, 15, 14, 13, 6, 3};
    int low = 0;
    int high = 9;

    int key;
    cout << "Enter the value you want to search: ";
    cin >> key;
    doSort(arr,10);
    bool status = binSer(arr, low, high, key);
    if(status == true)
    {
        cout << "Item is in the array" << endl;

    }
    else
    {
        cout << "Item is not in the array" << endl;
    }

    return 0;
}