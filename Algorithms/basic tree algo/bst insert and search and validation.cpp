#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node* left;
    node* right;
    node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
node* insertBST(node* root,int key){
    if(root==NULL) return new node(key);
    if(root->val>key) root->left=insertBST(root->left,key);
    else if(root->val<key) root->right=insertBST(root->right,key);
    return root;
}
void inorderPrint(node* root){
    if(root==NULL) return;
    inorderPrint(root->left);
    cout<<root->val<<" ";
    inorderPrint(root->right);
}
bool BSTSearch(node* root,int key){
    if(root==NULL) return false;
    if(root->val==key) return true;
    else if(root->val>key) return BSTSearch(root->left,key);
    else return BSTSearch(root->right,key);
    return false;
}
bool valid_BST(node* root,node* min,node* max){
    if(root==NULL) return true;
    if(min!=NULL && min->val>=root->val) return false;
    if(max!=NULL && max->val<=root->val) return false;
    return valid_BST(root->left,min,root) && valid_BST(root->right,root,max); 
}
int main(void){
    node* root=NULL;
    root=insertBST(root,10);
    insertBST(root,1);
    insertBST(root,87);
    insertBST(root,56);
    insertBST(root,3);
    insertBST(root,1000);
    insertBST(root,67);
    insertBST(root,50);
    insertBST(root,2);
    insertBST(root,100);
    inorderPrint(root);
    cout<<endl;
    if(BSTSearch(root,1)) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    if(valid_BST(root,NULL,NULL)) cout<<"Valid"<<endl;
    else cout<<"Invalid"<<endl;
}