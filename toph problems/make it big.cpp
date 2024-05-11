#include<bits/stdc++.h>
using namespace std;
int main(void){
int t;
cin>>t;
while(t--){
    string n,num,res;
    cin>>n;
    num=n;
    res=n;
    for(int i=0;i<n.length();i++){
        for(int j=0;j<n.length();j++){
            if(i!=j){
                for(int k=0;k<n.length();k++){
                    for(int l=0;l<n.length();l++){
                        if(k!=l){
                            swap(n[i],n[j]);
                            swap(n[k],n[l]);
                            num=max(num,n);
                            n=res;
                        }
                    }
                }
            }
        }
    }
    cout<<num<<endl;
}
}
