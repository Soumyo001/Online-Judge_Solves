#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main(void)
{
    int n;cin>>n;
    int count=0;
    multiset<int> s;
    if(n%2==0){
        while(n){
            count++;
            s.insert(2);
            n=n-2;
        }
    }else{
        n=n-3;
        while(n){
            count++;
            s.insert(2);
            n=n-2;
        }
        s.insert(3);
        count++;
    }
    cout<<count<<endl;
    for(auto& i:s) cout<<i<<" ";
}