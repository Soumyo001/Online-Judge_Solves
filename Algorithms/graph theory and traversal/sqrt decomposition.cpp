#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N],segment[N];
int preprocess(int n){
    int segpos=-1;
    int sze=sqrt(n);
    for(int i=0;i<n;i++){
        if(i%sze==0) segpos++;
        segment[segpos]+=arr[i];
    } 
    return sze;
}
int query(int segsize,int s,int e){
    int sum=0;
    while(s<e && s%segsize!=0){
        sum+=arr[s];s++;
    }
    while(s+segsize<=e){
        sum+=segment[s/segsize];
        s+=segsize;
    }
    while(s<=e){
        sum+=arr[s];s++;
    }
    return sum;
}
void update(int segsize,int i,int newVal){
    int pos=i/segsize;
    segment[pos]-=arr[i];
    segment[pos]+=newVal;
    arr[i]=newVal;
}
int main(void){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int sze=preprocess(n);
    while(true){
        int a,b,c;cin>>a>>b>>c;
        if(a==1) update(sze,b-1,c);
        else if(a==2) cout<<query(sze,b-1,c-1)<<endl;
        else break;
    }
}