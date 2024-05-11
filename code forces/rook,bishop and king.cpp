#include<bits/stdc++.h>
using namespace std;
int main(void){
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    int rook=0,bishop=0,king=0;
    if(r1==r2 || c1==c2){
        rook=1;
        if(r1==r2) {
            king=abs(c2-c1);
            // if((abs((c1+((c2-c1)/2))-c1)/((((c2-c1)/2)+r1)-r1))==1 && abs((c2-(c2-((c2-c1)/2)))/((((c2-c1)/2)+r1)-r1))==1){
            //     bishop=2;
            // }else bishop=0;
        }
        else {
            king = abs(r2-r1);
            // if((abs((r1+((r2-r1)/2))-r1)/((((r2-r1)/2)+c1)-c1))==1 && abs((r2-(r2-((r2-r1)/2)))/((((r2-r1)/2)+c1)-c1))==1){
            //     bishop=2;
            // }else bishop=0;    
        }
    }else{
        rook=2;
        king = max (abs(r2-r1),abs(c2-c1));
    }
    bishop=((r1+c1)%2==(r2+c2)%2)*(2-(r1-c1==r2-c2||r1+c1==r2+c2));
    cout<<rook<<" "<<bishop<<" "<<king<<endl;
}