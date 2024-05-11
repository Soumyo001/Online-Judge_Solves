#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val=0;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
struct List{
    int val=0;
    List* next;
    List(int val){
        this->val=val;
        next=NULL;
    }
};
List* head;
void insertAtTail(int data){
    List* p=new List(data);
    if(head==NULL){
        head=p;
        return;
    }
    List* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=p;
}
void __listToTree(Node* &root){
    queue<Node*> q;
    if(head==NULL){
        root=NULL;
        return;
    }
    root=new Node(head->val);
    List* temp=head;
    temp=temp->next;
    q.push(root);
    while(temp!=NULL){
        Node* parent=q.front();q.pop();
        if(temp!=NULL){
            Node* leftchild=new Node(temp->val);
            parent->left=leftchild;
            temp=temp->next;
            q.push(parent->left);
        }
        if(temp!=NULL){
            Node* rightchild=new Node(temp->val);
            parent->right=rightchild;
            temp=temp->next;
            q.push(parent->right);
        }
    }
}
void inorderTraversal(Node* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}
int main(void){
    Node* root=NULL;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        insertAtTail(x);
    }
    __listToTree(root);
    inorderTraversal(root);
}