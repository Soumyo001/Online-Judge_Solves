#include<bits/stdc++.h>
using namespace std;
class player{
  public:
    player(){}
    virtual string getName(){return "player";}
};
class gamer:public player{
private:
    string m_name;
public:
    gamer(string name){
        this->m_name=name;
    }
    void setName(string& name){name="Israk";this->m_name=name;}
    string getName()override{
        return m_name;
    }
};
void printName(player* p){
    cout<<p->getName()<<endl;
}
int main(void){
   player *p=new player();
   gamer *g=new gamer("Soumyo");
   cout<<p->getName()<<endl;
   cout<<g->getName()<<endl;
   //p=g;
   //cout<<p->getName()<<endl;
   printName(p);
   printName(g);
   string name="sadman";
   g->setName(name);
   cout<<g->getName()<<endl;
   cout<<name<<endl;
}