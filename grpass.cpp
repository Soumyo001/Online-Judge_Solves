#include<bits/stdc++.h>
using namespace std;
int main(void){
    vector<int>v;
    int t;cin>>t;
    while(t--){
    int n,temp=-1,count=0,num=0,x=0,r=0;cin>>n;
    v.clear();v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<n;){
        if(v[r]==v[i] && temp!=v[r])num++;
        temp=v[r];
        r++;i=r;
    }
    temp=-1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++) 
        {
            if (v[i] == v[j] && temp != v[j])
                count++;
        }
        temp = v[i];
        if (count == temp)
        {
            x++;
            count = 0;
        }
    }
    if(x==num) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
}