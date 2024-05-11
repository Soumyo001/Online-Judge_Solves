#include<bits/stdc++.h>
using namespace std;
int mal_mar(int l,int r,vector<int>& v){
    if(l==r) return 0;
    int ans=0;
    int mid=(l+r)>>1;
    int mal=*max_element(v.begin()+l,v.begin()+mid+1);
    int mar=*max_element(v.begin()+mid+1,v.begin()+r+1);
    if(mal>mar){
        ++ans;
        for(int i=0;i<(mid-l)+1;i++){
            swap(v[l+i],v[mid+1+i]);
        }
    }
    return mal_mar(l,mid,v)+mal_mar(mid+1,r,v)+ans;
}
void solve(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans=mal_mar(0,n-1,v);
    if(is_sorted(v.begin(),v.end())){
        cout<<ans<<endl;
    }else cout<<-1<<endl;
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}