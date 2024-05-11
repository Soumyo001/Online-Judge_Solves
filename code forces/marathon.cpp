#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        vector<int> v(5,0);
        int cnt=0;
        for(int i=0;i<4;i++){
            cin>>v[i];
            if(i>0 && v[i]>v[0]) cnt++;
        }
        cout<<cnt<<endl;
    }
}