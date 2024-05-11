#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main(void){
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        long long n,q;
        cin>>n>>q;
        ordered_set<long long> s;
        cout<<"Case "<<z<<":"<<endl;
        while(q--){
            char c;long long x;
            cin>>c>>x;
            if(c=='C'){

                
            }else{
                cout<<*(s.find_by_order(x-1))<<endl;
            }
        }
    }
}