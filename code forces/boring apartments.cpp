#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n%10==1){
            if(n==11) cout<<3<<endl;
            else if(n==111) cout<<6<<endl;
            else if(n==1111) cout<<10<<endl;
            else cout<<1<<endl;
        }else if(n%10==2){
            if(n==2) cout<<11<<endl;
            else if(n==22) cout<<13<<endl;
            else if(n==222) cout<<16<<endl;
            else cout<<20<<endl;
        }else if(n%10==3){
            if(n==3) cout<<21<<endl;
            else if(n==33) cout<<23<<endl;
            else if(n==333) cout<<26<<endl;
            else cout<<30<<endl;
        }else if(n%10==4){
            if(n==4) cout<<31<<endl;
            else if(n==44) cout<<33<<endl;
            else if(n==444) cout<<36<<endl;
            else cout<<40<<endl;
        }else if(n%10==5){
            if(n==5) cout<<41<<endl;
            else if(n==55) cout<<43<<endl;
            else if(n==555) cout<<46<<endl;
            else cout<<50<<endl;
        }else if(n%10==6){
            if(n==6) cout<<51<<endl;
            else if(n==66) cout<<53<<endl;
            else if(n==666) cout<<56<<endl;
            else cout<<60<<endl;
        }else if(n%10==7){
            if(n==7) cout<<61<<endl;
            else if(n==77) cout<<63<<endl;
            else if(n==777) cout<<66<<endl;
            else cout<<70<<endl;
        }else if(n%10==8){
            if(n==8) cout<<71<<endl;
            else if(n==88) cout<<73<<endl;
            else if(n==888) cout<<76<<endl;
            else cout<<80<<endl;
        }else if(n%10==9){
            if(n==9) cout<<81<<endl;
            else if(n==99) cout<<83<<endl;
            else if(n==999) cout<<86<<endl;
            else cout<<90<<endl;
        }
    }
}