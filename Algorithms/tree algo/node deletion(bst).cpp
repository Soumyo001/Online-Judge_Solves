#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
int Search(int* in_order,int start,int end,int curr){
    if(start>end) return -1;
    else if(*(in_order+start)==curr) return start;
    return Search(in_order,start+1,end,curr);
}
Node* __pre_in_orderTreeBuild(int start,int end,int pre_order[],int in_order[]){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre_order[idx];
    idx++;
    Node* p=new Node(curr);
    if(start==end) return p;
    int pos=Search(in_order,start,end,curr);
    p->left=__pre_in_orderTreeBuild(start,pos-1,pre_order,in_order);
    p->right=__pre_in_orderTreeBuild(pos+1,end,pre_order,in_order);
    return p;
}
Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr!=NULL && curr->left!=NULL) curr=curr->left;
    return curr;
}
Node* deleteInBST(Node* root,int key){
    if(key<root->data) root->left=deleteInBST(root->left,key);
    else if(key>root->data) root->right=deleteInBST(root->right,key);
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
        root->data=temp->data;
        root->right=deleteInBST(root->right,temp->data);
    }
    return root;
}
// Node* constructTree(Node* root,int key){
//     if(root==NULL) return new Node(key);
//     if(root->data>key) root->left=constructTree(root->left,key);
//     else if(root->data<key) root->right=constructTree(root->right,key);
//     return root;
// }
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(void){
    Node* root=NULL;
    int pre_order[]={50,40,30,20,35,45,41,49,69,60,55,80,95};
    int in_order[]={20,30,35,40,41,45,49,50,55,60,69,80,95};
    root=__pre_in_orderTreeBuild(0,sizeof(pre_order)/sizeof(pre_order[0])-1,pre_order,in_order);
    //int n;cin>>n;
    // for(int i=1;i<=n;i++){
    //     int k;cin>>k;
    //     root=constructTree(root,k);
    // }
    int key;cin>>key;
    inorder(root);
    cout<<endl;
    root=deleteInBST(root,key);
    inorder(root);
}