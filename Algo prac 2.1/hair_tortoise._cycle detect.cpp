#include<bits/stdc++.h>
using namespace std;
namespace __llist{
struct Node{
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};
Node* head;
void push_b(int key){
    Node* p=new Node(key);
    if(head==NULL){
        head=p;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=p;
}
void push_f(int key){
    Node* p=new Node(key);
    if(head==NULL){
        head=p;
        return;
    }
    p->next=head;
    head=p;
}
void __makecycle(int pos){
    Node* temp=head;
    Node* hold=NULL;
    int ct=0;
    while(temp->next!=NULL){
        ct++;
        if(ct==pos) hold=temp;
        temp=temp->next;
    }
    temp->next=hold;
}
bool __cycle_detect(){
    Node* fast=head;
    Node* slow=head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
void __remove_cycle(){
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    fast=head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
}
void print(Node* node){
    if(node==NULL) return;
    cout<<node->val<<" ";
    print(node->next);
}
}
using namespace __llist;
int main(void){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        push_b(x);
    }
    __makecycle(n/2);
    cout<<__cycle_detect()<<endl;
    if(__cycle_detect()) {__remove_cycle();print(head);}
    else cout<<"Nothing to do"<<endl;
}