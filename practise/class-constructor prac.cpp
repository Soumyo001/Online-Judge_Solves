#include<bits/stdc++.h>
using namespace std;
class Vector{
public :
  double x,y;
  Vector(){};
  Vector(double x1,double y1){
     x=x1;y=y1;
   }
   void printtVector(){
   cout<<x<<" "<<y<<endl;
   }
   Vector getScalerMultiple(double i){
     Vector vs(x*i,y*i);
     return vs;
   }
   double getProduct(Vector v){
      double pro=x*v.x+y*v.y;
      return pro;
   }
   void printVector(){
    cout<<x<<" "<<y<<endl;
   }
};
Vector add(Vector v1,Vector v2){
   Vector vs;vs.x=v1.x+v2.x;vs.y=v1.y+v2.y;return vs;
}
void callByAdress(Vector *v){
 (*v).printVector();
}
void scaleVector(Vector& v,double k){
   v.x*=k;v.y*=k;
}
class Line{
  public:
      double x,y;
      Vector points[2];
      Line(){};
      Line(Vector v1,Vector v2){
          points[0]=v1;points[1]=v2;
      }
      void printLine(){
        for(int i=0;i<2;i++) cout<<points[i].x<<" "<<points[i].y<<endl;
             //cout<<points[i].printVector()<<endl;;
      }
      double getDistance(Vector* v){
        return sqrt(pow((x-(*v).x),2)+pow((y-(*v).y),2));
      }
      void input(){
       cin>>x>>y;
      }
};
int main(void){
 Vector vs,r(6,6);
 cin>>vs.x>>vs.y;
 cout<<vs.getProduct(r)<<endl;
 Vector v=add(vs,r);
 cout<<v.x<<" "<<v.y<<endl;
 v=vs.getScalerMultiple(5.00);
 v.printtVector();vs.printVector();
 scaleVector(vs,5.00);
 vs.printVector();
 Line l(vs,r);
 l.printLine();
 callByAdress(&vs);
 l.input();
 cout<<l.getDistance(&vs)<<endl;
}
