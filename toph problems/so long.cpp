#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        int n,k;cin>>n>>k;
        long long jodu=0,modu=0,j,m;
        stack<long long> st;
        cout<<"Case "<<z<<":"<<endl;
        for(int i=0;i<n;i++){
            cin>>j>>m;
            if(m<j){
                modu=modu+m;
                while(!st.empty() && st.top()<j){
                    jodu=jodu+st.top();
                    st.pop();
                }
                if(st.size()<k) st.push(j);
            }else{
                jodu=jodu+j;
                while (!st.empty() && st.top()<m)
                {
                    modu=modu+st.top();
                    st.pop();
                }
                if(st.size()<k) st.push(m);
            }
            if(jodu>modu) cout<<"Jodu"<<endl;
            else if(jodu<modu) cout<<"Modu"<<endl;
            else if(jodu==modu) cout<<"Draw"<<endl;
        }
    }
}