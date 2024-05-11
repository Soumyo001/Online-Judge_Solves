#include<bits/stdc++.h>
using namespace std;
template<class T>
class root_finder
{
private:
    T arr[10000];
    int n,a,key;
    T x1=0,x2=0,x3=0,e;
    T f(T x){
        int j=n;
        int i=0;
        T p=arr[i];i++;
        while(j>0){
            p=(p*x)+arr[i];
            i++;j--;
        }
        return p;
    }
    pair<T,pair<T,T>> __rBisection(){
        do{
            x3=(x1+x2)/2;
            if(f(x3)*f(x1)<0) x2=x3;
            else x1=x3;
        }while(abs(f(x3))>e);
        return make_pair(x3,make_pair(x1,x2));
    }
    pair<T,pair<T,T>> __rFalsipos(){
        do{
            x3=x1-(((x1-x2)*f(x1))/(f(x1)-f(x2)));
            if(f(x3)*f(x1)<0) x2=x3;
            else x1=x3;
        }while(abs(f(x3))>e);
        return make_pair(x3,make_pair(x1,x2));
    }
    pair<T,pair<T,T>> __rSecant(){
        x3=x2-(((x2-x1)*f(x2))/(f(x2)-f(x1)));
        while(abs((x3-x2)/x3)>e){
            x1=x2;
            x2=x3;
            x3=x2-(((x2-x1)*f(x2))/(f(x2)-f(x1)));
        }
        return make_pair(x3,make_pair(x1,x2));
    }
public:
    root_finder(int n,int a,double x1,double x2,double e,double arr[],int key){
        this->n=n;
        this->a=a;
        this->x1=x1;
        this->x2=x2;
        this->e=e;
        this->key=key;
        for(int i=0;i<a;i++) this->arr[i]=arr[i];
    }
    pair<double,pair<double,double>> __rootFinder(){
        if(key==1) return __rBisection();
        else if(key==2) return __rFalsipos();
        else if(key==3) return __rSecant();
        else{
            cout<<"Wrong Choice"<<endl;
            exit(0);
        }
        return {0,{0,0}};
    }
};
double f(int n,double arr[],double x){
    int j=n;
    int i=0;
    double p=arr[i];i++;
    while(j>0){
        p=(p*x)+arr[i];
        i++;j--;
    }
    return p;
}
int main(void){
    int n,a,key;
    double x1,x2,e,arr[10000];
    cin>>n>>a>>x1>>x2>>e;
    for(int i=0;i<a;i++) cin>>arr[i];
    cin>>key;
    root_finder<double> r(n,a,x1,x2,e,arr,key);
    auto it=r.__rootFinder();
    cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
}