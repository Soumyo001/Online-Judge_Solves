#include<iostream>
#include<cmath>
using namespace std;

struct Sphere{
   double x,y,radius;
};

bool intersects(const Sphere& s1, const Sphere& s2){
   double distance = sqrt(pow(s1.x-s2.x,2) + pow(s1.y-s2.y,2));
   return distance<(s1.radius+s2.radius);
}

double volume(const Sphere& s){
   return 4*3.14159265*s.radius*s.radius*s.radius/3;
}

int main(){

   Sphere s1,s2;
   cout<<"Enter x and y coordinates for sphere #1: ";
   cin >> s1.x >> s1.y;
   cout<<"Enter radius: "; cin >> s1.radius;

   cout<<"Enter x and y coordinates for sphere #2: ";
   cin >> s2.x >> s2.y;
   cout<<"Enter radius: "; cin >> s2.radius;

   cout<<endl;

   cout<<"Sphere #1 Volume = " << volume(s1) << endl;
   cout<<"Sphere #2 Volume = " << volume(s2) << endl;

   cout<<boolalpha;
   cout<<"\Does the sphere interect? "<< intersects(s1,s2)<<endl;

   return 0;
}
