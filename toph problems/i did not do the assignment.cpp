#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    int flag=1;
    for(int i=2;i<n;i++){
          if(n%i==0) {
            flag=0;
            break;
          }
    }
    if(flag){
        cout<<"NO PUNISHMENT"<<endl;
    }else{
        for(int i=0;i<n;i++){
          cout<<"I DID NOT DO THE ASSIGNMENT."<<endl;
        }
    }
}