#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;cin>>n;
	map<long long,multiset<string>>m;
    m.clear();
	for(int i=0;i<n;i++){
		int x;string name;cin>>name>>x;
		m[-1*x].insert(name);
	}
	for(auto& it:m){
		for(auto& itr:it.second){
			cout<<itr<<" "<<-1*it.first<<endl;
		}
	}
}