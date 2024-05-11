#include<bits/stdc++.h>
using namespace std;
int main(void){
	int t;cin>>t;
	while(t--){
			int n,m,a,b,c,d;cin>>n>>m>>a>>b>>c>>d;
	//cout<<4-max((a==1 || a==n)+(b==1 || b==m),(c==1 || c==n)+(d==1 || d==m))<<endl;
	cout<<max((a==1 || a==n)+(b==1 || b==m),(c==1 || c==n)+(d==1 || d==m))<<endl;
	}
}
