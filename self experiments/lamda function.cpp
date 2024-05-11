#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<double> v1={4.5,3.6,5.7,8.9};
struct point{
     int x,y;
     point(){
        x=(rand()%10000)-5000;
        y=(rand()%10000)-5000;
     }
     void print(){
        cout<<"["<<x<<", "<<y<<"]";
     }
};
int main(void){
    vector<int> v={4,3,77,8,9,67,90,2};
    int a=10,b=5;
    double total=0;
    auto ck=[&]()->int{
        a=50,b=60;
        return a+b;
    };
    cout<<ck()<<" "<<a<<" "<<b<<endl;
    //sort(v.begin(),v.end());
    //for(int i:v) cout<<i<<" ";
    for_each(begin(v),end(v),[&](int x){
        total+=x;
    });
    cout<<total<<endl;
    cout<<all_of(v.begin(),v.end(),[&](int x)->bool{
        return x%2==0;
    })<<endl;
    for(int i:v) cout<<i<<" ";
    cout<<endl;
    vector<point>points;
    //point points[10];
    for(int i=0;i<10;i++) points.push_back(point());
    cout<<"before sort"<<endl;
    for(int i=0;i<10;i++) points[i].print();
    cout<<endl;
    sort(points.begin(),points.end(),[](const point& a,const point& b)->bool{
        return pow(a.x,2)+pow(a.y,2)<pow(b.x,2)+pow(b.y,2);
    });
    cout<<"after sort "<<endl;
    for(int i=0;i<10;i++) points[i].print();
}
