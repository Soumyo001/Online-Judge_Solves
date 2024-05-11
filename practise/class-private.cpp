#include<bits/stdc++.h>
using namespace std;
class Vector{
    private: double x,y;
    public:
       Vector(){};
       Vector(double x1,double y1){ x=x1;y=y1;}
       void setx(double xi){x=xi;}void sety(double yi){y=yi;}
       double getx(){return x;}double gety(){return y;}
       /*Vector getScalerMultiple(double k,Vector vx){
           Vector vs(vx.getx()*k,vx.gety()*k);
           return vs;
       }*/
       Vector getScalerMultiple(double k,Vector& v){
          //v.setx(v.getx()*k);v.sety(v.gety()*k);
          Vector vx(v.getx()*k,v.gety()*k);
          return vx;
       }
};
int main(void){
   Vector vs;
   double x,y;cin>>x>>y;
   vs.setx(x);vs.sety(y);
   Vector v=vs.getScalerMultiple(5.00,vs);
   cout<<v.getx()<<" "<<v.gety()<<endl;
   //cout<<vs.getx()<<" "<<vs.gety()<<endl;
   //vs.getScalerMultiple(5.00,vs);
   cout<<vs.getx()<<" "<<vs.gety()<<endl;
}
