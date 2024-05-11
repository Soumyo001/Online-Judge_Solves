#include<bits/stdc++.h>
using namespace std;
int main(void){
  string a,b;
  vector<int>st;
  int add,sub,multi,x=0,y=0;
  cin>>a>>b;
  for(int i=0;i<a.size();i++){
    if(a[i]>='0'&&a[i]<='9')
        x+=(a[i]-'0');
  }
  for(int i=0;i<b.size();i++){
    if(b[i]>='0'&&b[i]<='9')
        y+=(b[i]-'0');
  }
  st.push_back(x+y);st.push_back(x*y);st.push_back(abs(x-y));
  sort(st.begin(),st.end());
  cout<<'"'<<st[1]<<'"';
}
