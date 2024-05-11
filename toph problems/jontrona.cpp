#include<bits/stdc++.h>
using namespace std;
int f(long long a, int m){
	return (a * a + a) % m;
}

int solve(int N, int M, long long K){
	int a = N % M;
	for(int i = 0; i < K; i++){
		a = f(a, M);
	}
	return a;
}
int main(void){
    int t,n,m,k;cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k;
        cout<<"Case #"<<i<<": "<<solve(n,m,k)<<endl;
    }
}