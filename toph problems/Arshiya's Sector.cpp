#include<bits/stdc++.h>
using namespace std;
int main(void){
  int t;
  cin>>t;
  while(t--){
    int a,r;
    cin>>r>>a;
    cout<<fixed<<setprecision(9)<<((a/(double)360)*r*r*3.14159)<<endl;
  }
}
