#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        long long l,r;cin>>l>>r;
        if(l<=((r/2)+1)) cout<<(r-1)/2<<endl;
        else cout<<r-l<<endl;
    }
}
//maximum mod of r can be => if(l<=((r/2)+1)) then it can be shown that maximum mod is (r-1)/2 else if l is strictly greater than (r/2)+1 which means l > ((r/2)+1) then it will be (r-l) or r%l
// for example l=8 and r=26 then r/2=26/2=13+1=14 and 14*2=28 still the maximum mod can be (r-1)/2;
// if l > ((r/2)+1) then r=26=> 26/2=13+1=14 and 15>14 ;if l=15 then 15*2=30 which is greater than r=26; so the only max mod can be derived is (r-l)=26-15 or 26%15;