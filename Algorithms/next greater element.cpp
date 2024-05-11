#include<bits/stdc++.h>
using namespace std;
vector<int> ngf(vector<int>& v){
    vector<int>nge(v.size());
    stack<int> st;
    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[i]>v[st.top()]){
            nge[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nge[st.top()]=-1;
        st.pop();
    }
    return nge;
}
int main(void){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        int c;cin>>c;
        v[i]=c;
    }
    vector<int>v1=ngf(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" "<<v1[i]<<endl;
    }
}