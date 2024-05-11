#include<bits/stdc++.h>
using namespace std;
int main(void){
    #ifndef ONLINE_JUDGE
    freopen ("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;cin>>n;
    vector<int> days(n,0);
    for(int i=0;i<n;i++){
        int day;cin>>day;
        int bit=0;
        for(int j=0;j<day;j++){
            int x;cin>>x;
            bit |= (1<<x);
        }
        days[i]=bit;
    }
    int mx=INT_MIN,w1,w2;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int intersect=__builtin_popcount(days[i]&days[j]);
            if(mx<intersect){
                mx=intersect;
                w1=i,w2=j;
            }
        }
    }
    cout<<w1<<" "<<w2<<" "<<mx<<endl;
}