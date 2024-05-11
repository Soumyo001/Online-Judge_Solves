#include<iostream>
#include<vector>
#include<algorithm>
#include<stdint.h>
#include<map>
#include<set>
#include<array>
#include<functional>
#include<cmath>
#include<chanmgr.h>
#include<bits/atomic_lockfree_defines.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define ll long long
using namespace std;
void initcode(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n;cin>>n;
	vector<ll> a(n,0);
	vector<int> div;
	int same=1;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a[i]=abs(x);
		if(i>0 && a[i]!=a[i-1]) {same=0;if(n%i==0) div.push_back(i);}
	}
	if(same){
		cout<<0<<endl;return;
	}else if(n==2){
		cout<<abs(a[1]-a[0])<<endl;return;
	}
	ll mx = LLONG_MIN, mn = LLONG_MAX, ans = -1;
	int k=0;
	for(auto i:div) {
		mx = LLONG_MIN, mn = LLONG_MAX;
		for(int j=0;j<n;j+=i){
			ll ac=0;
			for(int z=j;z<j+i;z++) {
				ac+=a[z];
			}
			mx=max(mx,ac);
			mn=min(mn,ac);
		}
	    ans = max(ans, mx-mn);
		//for(int j=0;j<sum.size();j++) cout<<sum[j]<<" ";
		//for(int j=0;j<sum.size()-1;j++) for(int z=j+1;z<sum.size();z++) mx=max(mx,abs(sum[z]-sum[j]));
		//cout<<endl<<mx<<endl;
	}
    cout<<ans<<endl;
}
int main(void){
	initcode();
	int t;cin>>t;
	while(t--) solve();
}
/*
1
9
0
189114
112141
1891140907
*/