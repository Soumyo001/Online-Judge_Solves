#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int main(void){
    string s;cin>>s;
    if(s.length()==1){
        cout<<s<<endl;
        return 0;
    }
    multiset<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]!='+'){
            st.insert(s[i]-'0');
        }
    }
    string ans="";
    for(auto& i:st){
        ans+=(i+'0');
        ans+='+';
    }
    ans.pop_back();
    cout<<ans<<endl;
}