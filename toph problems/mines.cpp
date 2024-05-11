#include<bits/stdc++.h>
using namespace std;
int main(void){
 int r,c,coun=0;
 cin>>r>>c;
 char s[25][25];
 for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>s[i][j];
    }
 }
 for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(s[i][j]=='.'){
            coun=0;
            if(s[i][j+1]=='*')coun++;
            if(s[i-1][j]=='*')coun++;
            if(s[i+1][j+1]=='*')coun++;
            if(s[i][j-1]=='*')coun++;
            if(s[i-1][j-1]=='*')coun++;
            if(s[i-1][j+1]=='*')coun++;
            if(s[i+1][j]=='*')coun++;
            if(s[i+1][j-1]=='*')coun++;
            if(coun!=0){s[i][j]=(char)(coun+'0');cout<<s[i][j];}
            else {cout<<s[i][j];}
        }
        else cout<<s[i][j];
    }
    cout<<endl;
 }

}
