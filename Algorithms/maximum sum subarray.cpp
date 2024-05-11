#include<bits/stdc++.h>
using namespace std;
int main(void){
    int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n=8,ans=INT_MIN;
    for(int start_index=0;start_index<n;start_index++){
        int sum=0;
        for(int sub_array=start_index;sub_array<n;sub_array++){
            //if(start_index+sub_array>n) break;
            sum+=a[sub_array];
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}