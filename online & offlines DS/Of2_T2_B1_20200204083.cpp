#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        a.push_back(v);
    }
    for(int i=0;i<a.size()-1;i++){
        for(int j=0;j<a.size()-1;j++){
            if(a[j+1]<a[j]){
               int temp=a[j+1];
               a[j+1]=a[j];
               a[j]=temp;
            }
        }
    }
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}