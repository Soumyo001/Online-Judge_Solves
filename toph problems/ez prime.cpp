#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<bool> v(N,1);
void sievePrime(){
    v[0]=false,v[1]=false;
    for(int i=2;i<N;i++){
        if(v[i]==true){
            for(int j=i*2;j<N;j+=i){
                v[j]=false;
            }
        }
    }
}
int32_t main(void){
    int n;cin>>n;
    int x[n+1];
    for(int i=0;i<n;i++) cin>>x[i];
    int q;cin>>q;
    sievePrime();
    for(int i=1;i<=q;i++){
        int count=0;
        int a,b,c;cin>>a>>b>>c;
        if(a==1){
            for(int i=b-1;i<c;i++){
                if(v[x[i]]) count++;
            }
            cout<<count<<endl;
        }else if(a==2){
            x[b-1]=c;
        }
    }
}