#include<bits/stdc++.h>
using namespace std;
int dx[]={-2,-2, 2,2,-1,-1, 1,1};
int dy[]={-1, 1,-1,1,-2, 2,-2,2};
bool valid(int x,int y,int n){
    return x>=0 && y>=0 && x<n && y<n;
}
bool isSafe(int** arr,int x,int y,int n){
    for(int i=0;i<8;i++) if(valid(x+dx[i],y+dy[i],n)) if(arr[x+dx[i]][y+dy[i]]==1) return false;
    return true;
}
bool nHorse(int** arr,int x,int n){
    if(x>=n) return true;
    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            if(nHorse(arr,x+1,n)) return true;
            arr[x][col]=0;
        }
    }
    return false;
}
int main(void){
    int n;cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++) arr[i][j]=0;
    }
    if(nHorse(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }
}