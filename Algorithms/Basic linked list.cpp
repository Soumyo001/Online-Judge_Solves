#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *next;
    node(int val){
       this->val=val;
       next=NULL;
    }
};
int main(void){
     node n1(5);
     node n2(6);
     node n3(7);
     n1.next=&n2;
     n2.next=&n3;
     node *head=&n1;
     while(head!=NULL){
        cout<<head->val<<endl;
        head=head->next;
     }
}