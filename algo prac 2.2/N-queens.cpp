#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
bool isSafe(int** arr, int x, int y, int n){
    for(int i = 0; i<x;i++) if(arr[i][y] == 1) return false;
    int row = x;
    int col = y;
    while(row >= 0 && col >= 0){
        if(arr[row][col] == 1) return false;
        row--;
        col--;
    }
    row = x;
    col = y;
    while(row >= 0 && col < n){
        if(arr[row][col] == 1) return false;
        row--;
        col++;
    }
    return true;
}
bool nQueen(int** arr, int x, int n){
    if(x >= n) return true;
    for(int y = 0; y < n; y++){
        if(isSafe(arr,x,y,n)){
            arr[x][y] = 1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][y] = 0;
        }
    }
    return false;
}
int main(void){
    int n;cin>>n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++) arr[i][j]=0;
    }
    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }
}