#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int n,m,x,steps=0;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++) cin>>b[i];
    sort(b+0,b+m);
    cin>>x;
    int i=n-1,s=0,ct=0;
    for(i=n-1;;){
        if(i<0){
           ct++;
           if(ct==10) break;
           else i=n-1; 
        }
        if(steps==x){
            cout<<"Yes"<<endl;return 0;
        }
        steps+=a[i];
        for(int j=s;j<m;j++){
            if(steps==b[j] || steps>x) {
                steps-=a[i];
                i--;break;
            }else if(steps>b[j]) s=j;
        }
    }
    cout<<"No";
}