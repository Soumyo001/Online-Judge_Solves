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
    else if(root->val<key)root->right=insertBST(root->right,key);
    return root;
}
void inorderPrint(node* root){
    if(root==NULL) return;
    inorderPrint(root->left);
    cout<<root->val<<" ";
    inorderPrint(root->right);
}
int main(void){
    node* root=NULL;
    root=insertBST(root,10);
    insertBST(root,1);
    insertBST(root,8);
    insertBST(root,5);
    insertBST(root,3);
    insertBST(root,6);
    insertBST(root,5);
    insertBST(root,1);
    insertBST(root,10);
    insertBST(root,1000);
    inorderPrint(root);
    cout<<endl;
}