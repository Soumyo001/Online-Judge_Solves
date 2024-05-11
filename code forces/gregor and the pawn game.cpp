#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int mxpawn=0;
        string ep,gp;cin>>ep>>gp;
        for(int i=0;i<n;i++){
            if(gp[i]=='1'){
                if((i>=0 && i<n) && ep[i]=='0'){
                    mxpawn++;
                    ep[i]='g';
                }else if(i==0 && ep[i]=='1'){
                    if(ep[i+1]=='1'){
                        ep[i+1]='g';
                        mxpawn++;
                    }
                }else if(i==(n-1) && ep[i]=='1'){
                    if(ep[i-1]=='1'){
                        ep[i-1]='g';
                        mxpawn++;
                    }
                }else if(i>0 && ep[i-1]=='1'){
                    mxpawn++;
                    ep[i-1]='g';
                }else if(i<n-1 && ep[i+1]=='1'){
                    mxpawn++;
                    ep[i+1]='g';
                }
            }
        }
        cout<<mxpawn<<endl;
    }
}