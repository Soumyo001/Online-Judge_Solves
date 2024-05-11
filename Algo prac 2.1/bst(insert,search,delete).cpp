#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        left=right=NULL;
    }
};
Node* insertNode(Node* root,int key){
    if(root==NULL) return new Node(key);
    if(root->val>key) root->left=insertNode(root->left,key);
    else if(root->val<key) root->right=insertNode(root->right,key);
    return root;
}
bool search(Node* root,int key){
    if(root==NULL) return false;
    if(root->val==key) return true;
    else if(root->val>key) return search(root->left,key);
    else return search(root->right,key);
    return false;
}
Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr!=NULL && curr->left!=NULL) curr=curr->left;
    return curr;
}
Node* deleteNode(Node* root,int key){
    if(root->val>key) root->left=deleteNode(root->left,key);
    else if(root->val<key) root->right=deleteNode(root->right,key);
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inorderSucc(root->right);
        root->val=temp->val;
        root->right=deleteNode(root->right,temp->val);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(void){
    Node* root=NULL;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        root=insertNode(root,x);
    }
    inorder(root);cout<<endl;
    for(int i=1;i<=n;i++){
        int x;cin>>x;cout<<search(root,x)<<endl;
    }
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        root=deleteNode(root,x);
        inorder(root);cout<<endl;
    }
}