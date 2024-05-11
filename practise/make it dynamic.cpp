#include<bits/stdc++.h>
using namespace std;
int main(void){
  int c;
  cin>>c;
  for(int i=1;i<=(c*3)-2;i++){
    for(int j=1;j<=(c*3)-2;j++){
            if(i==1||i==(c*3)-2){
                  if(j>=c&&j<=((c*2)-1)) cout<<"*";
                  else cout<<" ";
            }
            if((i>=2&&i<=c-1)||(i>=c*2&&i<=((c*3)-3))){
                if(j==c||j==((c*2)-1)) cout<<"*";
                else cout<<" ";
            }
            if(i==c||i==((c*2)-1)){
                if((j>=1&&j<=c)||(j>=((c*2)-1)&&j<=((c*3)-2))) cout<<"*";
                else cout<<" ";
            }
            if(i>c&&i<((c*2)-1)){
                if(j==1||j==((3*c)-2)) cout<<"*";
                else cout<<" ";
            }
    }
    cout<<endl;
  }
}
