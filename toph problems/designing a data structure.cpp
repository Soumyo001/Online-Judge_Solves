#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
using namespace std;
list<int>l;
int main(void){
    int q;cin>>q;
    while(q--){
        string s;string p;cin>>s;cin>>p;
        if(s=="Insert"){
            int x;cin>>x;
            if(p=="Back")l.push_back(x);
            else l.push_front(x);
        }else if(s=="Erase"){
            if(p=="Front") l.pop_front();
            else l.pop_back();
        }else if(s=="Get"){
            if(p=="Front") cout<<l.front()<<endl;
            else if(p=="Back")cout<<l.back()<<endl;
            else if(p=="Max") cout<<*(max_element(l.begin(),l.end()))<<endl;
            else cout<<*(min_element(l.begin(),l.end()))<<endl;
        }
    }
}