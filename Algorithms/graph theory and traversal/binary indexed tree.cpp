#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int BIT[N];
int n;
int sum(int idx){
    int sum=0;
    while (idx>0)
    {
       sum+=BIT[idx];
       idx=idx-(idx& (-idx));
    }
    return sum;
}
void update(int idx,int val){
    while(idx<=n){
        BIT[idx]+=val;
        idx=idx+(idx& (-idx));
    }
}
int main(void){
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;++i){
        cin>>arr[i];
        update(i,arr[i]);
    }
    while (true)
    {
        int x;cin>>x;
        if(x==1){
            int v;cin>>v;
            cout<<sum(v)<<'\n';
        }else if(x==2){
            int b,e;cin>>b>>e;
            cout<<sum(e)-sum(b-1)<<'\n';
        }else break;
    }
    
}