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
void insertAttail(node* &head,int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void insertAthead(node* &head,int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;return;
    }
    n->next=head;
    head->prev=n;
    head=n;
}
void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void reverseDisplay(node *head){
    node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}
void addNode(node* &head,int pos,int value){
    node *temp=head;
    node *p=new node(value);
    node *t;
    int x=0;
    while(temp!=NULL){
        x++;
        if(pos==1){
            insertAthead(head,value);
            return;
        }
        if(x==pos-1){
            p->next=temp->next;
            p->prev=temp;
            temp->next=p;
            if(p->next!=NULL) p->next->prev=p;
        }
        temp=temp->next;
    }
}
void swapNode(node* &head){
    node *temp=head;
    int ma=INT_MIN,mi=INT_MAX;
    node *maximum=head,*minimum=head;
    while(temp!=NULL){
        if(ma<temp->val){
            ma=temp->val;
            maximum=temp;
        }
        if(mi>temp->val){
            mi=temp->val;
            minimum=temp;
        }
        temp=temp->next;
    }
    node *a,*b,*t;
    a=maximum->next;
    b=minimum->next;
    t=maximum;
    maximum=minimum;
    minimum=t;
    maximum->next=b;
    minimum->next=a;
}
int main(void){
    node *head=NULL;
    insertAttail(head,893);
    insertAttail(head,47);
    insertAttail(head,1873);
    insertAttail(head,567);
    insertAttail(head,4);
    insertAttail(head,64);
    insertAttail(head,70);
    display(head);
    insertAthead(head,24);
    insertAthead(head,10);
    insertAthead(head,1);
    display(head);
    //swapNode(head);
    //display(head);
    addNode(head,3,66);
    addNode(head,7,0);
    addNode(head,4,8);
    addNode(head,2,6);
    addNode(head,1,83);
    addNode(head,1,60);
    addNode(head,1,500);
    insertAttail(head,1000);
    addNode(head,19,700);
    display(head);
    reverseDisplay(head);
    addNode(head,3,99);
    display(head);
    reverseDisplay(head);
    //swapNode(head);
    //display(head);
}
