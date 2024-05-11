#include<bits/stdc++.h>
using namespace std;
int main(void){
    int min;
    int a[]={1000,6,3,0,5,52,63,6,2,4,78,43,23,1,22,678,123,5656,866,8898756,123,434,5655,778,98,90,656,45,7,6,3,6,345,5679,567,99,7656,75632,3445,56456,677,67,56,56,7,67,45,64,6,456,456,3,5,2345,3,6,8,89,789,65,45,64,56,457,8,7,5};
    for(int i=0;i<(sizeof(a)/sizeof(a[0]))-1;i++){
        min=i;
        for(int j=i+1;j<sizeof(a)/sizeof(a[0]);j++){
             if(a[min]>a[j]) min=j;
        }
        swap(a[i],a[min]);
    }
    for(int i:a) cout<<i<<" ";
}