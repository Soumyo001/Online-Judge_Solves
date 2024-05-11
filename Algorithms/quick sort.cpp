#include<bits/stdc++.h>
using namespace std;
//first element as pivot
/*int partition(int a[],int l,int r){
    int pivot=a[l],i=l;
    for(int j=l+1;j<=r;j++){
        if(a[j]<pivot){
             i++;
             swap(a[i],a[j]);
        }
    }
    swap(a[i],a[l]);
    return i;
}
//last element as pivot
int partition(int a[],int l,int r){
    int pivot=a[r],i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
             i++;
             swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}*/
//mid element as pivot
int partition(int a[],int l,int r){
    int mid=(l+r)/2;
    int pivot=a[mid];
    int i=l-1;
    for(int j=l;j<mid;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[mid]);
    i++;int loc=i;//pivot=a[i+1];
    for(int j=mid+1;j<=r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i],a[loc]);
    return i;
}
//random element as pivot
int partition01(int a[],int l,int r,int pNum){
    //int mid=(l+r)/2;
    pNum=l+pNum-1;
    int pivot=a[pNum];
    int i=l-1;
    for(int j=l;j<pNum;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[pNum]);
    i++;int loc=i;//pivot=a[i+1];
    for(int j=pNum+1;j<=r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i],a[loc]);
    return i;
}
void quicksort(int a[],int l,int r,int pNum=2){
    if(l<r){
      int pi=partition01(a,l,r,pNum);
      quicksort(a,l,pi-1);
      quicksort(a,pi+1,r);
    }
}
int main(void){
    int a[]={1000,6,3,0,5,52,63,6,2,4,78,43,23,1,22,678,123,5656,866,8898756,123,434,5655,778,98,90,656,45,7,6,3,6,345,5679,567,99,7656,75632,3445,56456,677,67,56,56,7,67,45,64,6,456,456,435,5,64,546,65,546,7,67,5,68,587,6789,679,7,65,65,546,345,53,54,5,234,2,43,41243,4534,654,7,568,48,58,67,9,9,6543,6,362,3657,76,85,678,5473,65,7,67,7,8,6453,7,76,675,654,6543,543,435,532,5,3,421,4,6543,678,8679,8670,4653,643,465305643,32,6043567,0,546,45,4357,740,57,54,7043,507,347,435,706,34,6,547,45,6,4673,4,75,587,3568,3,5,2345,3,6,8,89,789,65,45,64,56,457,8,7,5};
    quicksort(a,0,sizeof(a)/sizeof(a[0])-1);
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++) cout<<a[i]<<" ";
}