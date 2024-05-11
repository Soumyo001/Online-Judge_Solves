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
void __inorder(Node* root){
    if(root==NULL) return;
    __inorder(root->left);
    cout<<root->val<<" ";
    __inorder(root->right);
}
int __levelSum(Node* root,int level){
    int sum=0;
    int k=0;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();q.pop();
        if(temp!=NULL){
            if(k==level) sum+=temp->val;
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }else if(!q.empty()){
            k++;q.push(NULL);
        }
    }
    return sum;
}
int main(void){
    Node* root=NULL;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        root=insertNode(root,x);
    }
    __inorder(root);cout<<endl;
    cout<<__levelSum(root,2)<<endl;
    cout<<__levelSum(root,3)<<endl;
}