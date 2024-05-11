#include<bits/stdc++.h>
using namespace std;
int getBit(int a,int k){return a&(1<<k);}
void setBit(int& a,int k){a=(a|(1<<k));}
void toggleBit(int& a,int k){a=(a^(1<<k));}
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n+1);
        int mxV=INT_MIN;
        for(int i=1;i<=n;i++) cin>>v[i];
        sort(v.begin()+1,v.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int b=0;b<=11;b++){
                    if(getBit(v[i],b)!=getBit(v[j],b)){
                        toggleBit(v[i],b);
                        toggleBit(v[j],b);
                    }
                    int a=*max_element(v.begin()+1,v.end());
                    int x=*min_element(v.begin()+1,v.end());
                    mxV=max(mxV,a-x);
                }
            }
        }
        cout<<mxV<<endl;
    }
}