#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
        map<int,int>m;
        int mx=INT_MIN,mn=INT_MAX;
        while(n--){
            int x;cin>>x;m[x]++;
        }
        mx=max_element(m.begin(),m.end(),[](const pair<int, int>& p1, const pair<int, int>& p2)->bool{
        return p1.second < p2.second;
        })->second;
        mn=min_element(m.begin(),m.end(),[](const pair<int, int>& p1, const pair<int, int>& p2)->bool{
        return p1.second < p2.second;
        })->second;
        int ans=mx-mn;
        cout<<mx<<" "<<mn;
	}
}