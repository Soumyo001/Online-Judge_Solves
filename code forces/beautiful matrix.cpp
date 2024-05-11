#include<bits/stdc++.h>
using namespace std;
int matrix[6][6];
int main(void){
    int row,col;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]==1) {
                row=i;col=j;
            }
        }
    }
    cout<<abs(2-row)+abs(2-col)<<endl;
}