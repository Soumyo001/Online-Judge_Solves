#include<bits/stdc++.h>
using namespace std;
int main(void){
    vector<int> v;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<"Enter the element you want to find: ";
    cin>>a;
    int x;
    for(int i=0;i<v.size();i++){
        if(v[i]==a){
            x=i;
            break;
        }
    }
    cout<<x<<endl;
}