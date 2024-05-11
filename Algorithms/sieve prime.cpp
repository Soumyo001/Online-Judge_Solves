#include<bits/stdc++.h>
using namespace std;
const int n=1e6+10;
int main(void){
    vector<bool>v(n,1);
    v[0]=false,v[1]=false;
    for(int i=2;i<n;i++){
        if(v[i]==true){
            for(int j=2*i;j<n;j+=i){
                  v[j]=false;
             }
        }
    }
    for(int i=1;i<=100;i++){
        cout<<i<<" "<<v[i]<<endl;
    }
}