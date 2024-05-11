#include<bits/stdc++.h>
using namespace std;
int main(void){
    vector<int>a;
    int n;cin>>n;
    for(int i=0;i<n;i++){
       int v;cin>>v;
       a.push_back(v); 
    }
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
             if(a[min]>a[j]){
                 min=j;
             }
        }
        swap(a[i],a[min]);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}