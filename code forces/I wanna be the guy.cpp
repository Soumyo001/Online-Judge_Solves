#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int arr[100];

int main(void){
    int n;
    set<int>s;
    int p,flag=1;cin>>n>>p;
    for(int i=0;i<p;i++){
        int x;cin>>x;
        s.insert(x);
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int x;cin>>x;
        s.insert(x);
    }
    if(s.size()==n) cout<<"I become the guy."<<endl;
    else cout<<"Oh, my keyboard!"<<endl;
}