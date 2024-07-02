#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int BIT[N],arr[N];
int n,q;
void update(int idx,int val){
    while(idx<=n){
        BIT[idx]+=val;
        idx = idx + (idx & (-idx));
    }
}
int sum(int idx){
    int sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx=idx-(idx& (-idx));
    }
    return sum;
}
int main(void){
    iostream::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    for(int k=1;k<=t;++k){
        cin>>n>>q;
        for(int i=1;i<=n;++i) BIT[i]=0;
        for(int i=1;i<=n;++i){
            cin>>arr[i];
            update(i,arr[i]);
        }
        cout<<"Case "<<k<<":\n";
        while(q--){
            int x,i,j,v;cin>>x;
            if(x==1){
                cin>>i;
                cout<<arr[i+1]<<'\n';
                update(i+1,-arr[i+1]);
                arr[i+1]=0;
            }else if(x==2){
                cin>>i>>v;update(i+1,v);
                arr[i+1]+=v;
            }else{
                cin>>i>>j;
                cout<<sum(j+1)-sum(i+1-1)<<'\n';
            }
        }
    }
}