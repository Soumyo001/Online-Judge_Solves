#include <bits/stdc++.h>
using namespace std;
void initcode(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int ans=0;
	int n;cin>>n;
	vector<int> a(n,0);
	int temp;
	int flag=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			ans^=a[j];
		}
		for(int j=0;j<n;j++){
			if(a[j]==ans){
				temp=ans;
			}
		}
	}
	cout<<temp<<endl;
}
int main(void){
	//initcode();
	int t;cin>>t;
	while(t--) solve();
}