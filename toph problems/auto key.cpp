#include <bits/stdc++.h>
using namespace std;

/*int main()
{
    // Create a set of strings
    set<string> st;
    st.insert({ "geeks", "for",
               "geeks", "org" });

    // 'it' evaluates to iterator to set of string
    // type automatically
    for (auto it = st.begin();
         it != st.end(); it++)
        cout << *it << " ";

    return 0;
}*/
int main (void){
  /*auto a=10;
  auto b=a;
  b=a-6;
  cout<<b<<endl<<a<<endl;
  a+=10;
  cout<<a<<endl;
  a++;
  cout<<a;*/
  auto b=50;
  auto *a=&b;
  decltype(a) j;
  j=&b;
  cout<<typeid(j).name()<<endl<<*a+5<<endl<<j<<endl<<*j<<endl;
  decltype(b) x;
  x=20;
  b+=5;
  cout<<typeid(x).name()<<endl<<x<<endl<<b;
}
