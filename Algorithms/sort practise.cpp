#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int r){
    int pivot=a[r],j=l-1;
    for(int i=l;i<=r;i++){
        if(pivot>a[i]){
            j++;
            swap(a[j],a[i]);
        }
    }
    swap(a[j+1],a[r]);
    return j+1;
}
void qsort(int a[],int l,int r){
    if(l<r){
        int pi=partition(a,l,r);
        qsort(a,l,pi-1);
        qsort(a,pi+1,r);
    }
}
void mergesort(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++) a[i]=arr[l+i];
    for(int i=0;i<n2;i++) b[i]=arr[mid+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;i++;
        }else{
            arr[k]=b[j];
            k++;j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;j++;
    }
}
void merge(int a[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge(a,l,mid);
        merge(a,mid+1,r);
        mergesort(a,l,mid,r);
    }
}
void insertionSort(int a[],int size){
    for(int i=1;i<size;i++){
        int curr=a[i];
        int j=i-1;
        while(a[j]>curr && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=curr;
    }
}
void selSort(int a[],int size){
    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(a[min]>a[j]) min=j;
        }
        swap(a[i],a[min]);
    }
}
int main(void)
{
    int a[]={5,345,678,2,6,4,8,89,22,67,1543,6,56,7456,7889889,8,6,86,7,5,867,456,456,47,3,24,67,6,0,2,1,5};
    while(1){
    cout<<"1.qsort"<<endl<<"2.mergeSort"<<endl<<"3.selSort"<<endl<<"4.InsertionSort"<<endl;
    int n;cin>>n;
    switch (n)
    {
    case 1:
        qsort(a,0,sizeof(a)/sizeof(a[0])-1);
        for(int i:a) cout<<i<<" ";
        cout<<endl;
        break;
    case 2:
        merge(a,0,sizeof(a)/sizeof(a[0])-1);
        for(int i:a) cout<<i<<" ";
        cout<<endl;
        break;
    case 3:
       selSort(a,sizeof(a)/sizeof(a[0]));
       for(int i:a) cout<<i<<" ";
       cout<<endl;
       break;
    case 4:
       insertionSort(a,sizeof(a)/sizeof(a[0]));
       for(int i:a) cout<<i<<" ";
       cout<<endl;
       break;
    case 5:
       return -1000000;
       break;
    default:
        break;
    }
    }
}
