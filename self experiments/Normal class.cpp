#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class player{
    public:
    int x,y,speed;
    void move(int xa,int ya){
         x+=xa; y+=ya;
    }
};
void keyBindings(player *player){
              int game=1;
              if(kbhit()){
              switch(getch()){
                   case 'd':{
                       (*player).move(-1,1);
                       cout<<(*player).x<<" "<<(*player).y<<endl;
                       break;
                   }
                   case 'a':{
                       (*player).move(1,-1);
                       cout<<(*player).x<<" "<<(*player).y<<endl;
                       break;
                   }
                   case 'x':{
                       game=false;
                       break;
                   }
              }
          }
}
int main(void){
          player player;
          int a,b,c;cin>>player.x>>player.y>>player.speed;
          cout<<player.x<<" "<<player.y<<" "<<player.speed<<endl;
          bool game=true;
          while(game){
              keyBindings(&player);
          }
}
