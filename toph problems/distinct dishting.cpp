#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N];
struct info{
    unordered_map<int,int>m;
    long long val=0;
}seg[N];
unordered_map<int,int> mp;
int preprocess(int n){
    int cur_seg=-1;
    int seg_size=sqrt(n);
    for(int i=0;i<n;i++){
        if(i%seg_size==0) cur_seg++;
        if(arr[i]%3==0 && seg[cur_seg].m[arr[i]]==0){
            seg[cur_seg].val+=arr[i];
            seg[cur_seg].m[arr[i]]++;
        }
    }
    return seg_size;
}
long long query(int seg_size,int l,int r){
    long long sum=0;
    while(l<r && l%seg_size!=0){
        sum+=(mp[arr[l]]==0 && arr[l]%3==0 ? arr[l]:0);
        mp[arr[l]]++;
        l++;
    }
    while(l+seg_size-1<=r){
        sum+=seg[l/seg_size].val;
        l+=seg_size;
    }
    while(l<=r){
        sum+=(mp[arr[l]]==0 && arr[l]%3==0 ? arr[l]:0);
        mp[arr[l]]++;
        l++;
    }
    return sum;
}
void update(int seg_size,int i,int newVal){
    int idx=i/seg_size;
    if(arr[i]%3==0){
        seg[idx].val-=arr[i];
        seg[idx].m[arr[i]]=0;
    }
    if(newVal%3==0 && seg[idx].m[newVal]==0) {seg[idx].val+=newVal;seg[idx].m[newVal]++;}
    arr[i]=newVal;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    int sz=preprocess(n);
    for(int i=0;i<q;i++){
        int a,b,c;cin>>a>>b>>c;
        if(a==0) update(sz,b-1,c);
        else if(a==1) mp.clear(),cout<<query(sz,b-1,c-1)<<endl;
    }
}