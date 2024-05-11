#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *next,*prev;
    node(int val){
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};
void insertAtTail(node* &head,int val){
    node *p=new node(val);
    if(head==NULL){
       head=p;
       return;
    }
    node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=p;
    p->prev=temp;
}
void insertAtHead(node* &head,int val){
    node *p=new node(val);
    if(head==NULL){
        head=p;
        return;
    }
    p->next=head;
    head->prev=p;
    head=p;
}
void display(node* &head){
   node *temp=head;
   int x=0;
   while (temp!=NULL)
   {
       x++;
       cout<<temp->val<<" ";
       temp=temp->next;
   }
   cout<<endl;
   cout<<x<<endl;
}
void sortList(node* &head){
    node *temp=head;
    node *temp1=head;
    int x=0;
    while (temp!=NULL){
         x++;temp=temp->next;
    }
    temp=temp1;temp1=temp1->next;
    //for(int i=0;i<x-1;i++){
       //for(int j=i+1;j<x;j++){
    while(temp->next!=NULL){
        while(temp1!=NULL){
           if(temp->val>temp1->val){
                 int v=temp1->val;
                 temp1->val=temp->val;
                 temp->val=v;
           }
           temp1=temp1->next;
       }
       temp=temp->next;
       temp1=temp->next;
    }

}
void addNode(node* &head,int n,int val){
    int x=0;
    node *temp=head;
    while(temp!=NULL){
        x++;
        if(n==1) {
            insertAtHead(head,val);
            return;
        }
        if(x==n-1){
            node *p=new node(val);
            p->next=temp->next;
            p->prev=temp;
            temp->next=p;
            if(p->next!=NULL) p->next->prev=p;
        }
        temp=temp->next;
    }
}
int main(void){
    node *n=NULL;
   insertAtHead(n,5);
   insertAtHead(n,8);
   insertAtHead(n,7);
   insertAtHead(n,9);
   display(n);
   insertAtTail(n,10);
   insertAtTail(n,45);
   insertAtTail(n,324);
   insertAtTail(n,320);
   insertAtTail(n,324);
   insertAtTail(n,324);
   insertAtTail(n,324);
   insertAtTail(n,324);
   insertAtTail(n,71);
   insertAtTail(n,72);
   insertAtTail(n,75);
   insertAtTail(n,78);
   insertAtTail(n,745360);
   insertAtTail(n,435340);
   insertAtTail(n,70);
   insertAtTail(n,450);
   insertAtTail(n,3454350);
   insertAtTail(n,3405434);
   insertAtTail(n,7043664);
   insertAtTail(n,7024334);
   insertAtTail(n,7056656);
   insertAtTail(n,746765674);
   insertAtTail(n,237356);
   insertAtTail(n,566);
   insertAtTail(n,543);
   insertAtTail(n,45);
   insertAtTail(n,12324);
   insertAtTail(n,32);
   insertAtTail(n,342);
   insertAtTail(n,23);
   insertAtTail(n,123);
   insertAtTail(n,45);
   insertAtTail(n,34);
   insertAtTail(n,90);
   insertAtTail(n,10);
   insertAtTail(n,20);
   insertAtTail(n,30);
   insertAtTail(n,40);
   insertAtTail(n,0);
   insertAtTail(n,90);
   display(n);
   addNode(n,1,50000);
   addNode(n,3,60000);
   addNode(n,2,656);
   display(n);
   sortList(n);
   display(n);
   addNode(n,48,900000);
   addNode(n,47,570000);
   display(n);
}
