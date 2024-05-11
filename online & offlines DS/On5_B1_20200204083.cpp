#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *root = NULL;

void create_tree()
{
    Node *four = new Node(4);
    Node *two = new Node(2);
    Node *one = new Node(1);
    Node *three = new Node(3);
    Node *six = new Node(6);
    Node *five = new Node(5);
    Node *seven = new Node(7);
    four->left =two;
    four->right = six;
    two->left = one;
    two->right = three;
    six->left = five;
    six->right = seven;

    root = four;
}


void pre_order(Node *node)
{
   if(node==NULL) return;
   cout<<node->data<<" ";
   pre_order(node->left);
   pre_order(node->right);
}

void in_order(Node *node)
{
   if(node==NULL) return;
   in_order(node->left);
   cout<<node->data<<" ";
   in_order(node->right);
}

void post_order(Node *node)
{
   if(node==NULL) return;
   post_order(node->left);
   post_order(node->right);
   cout<<node->data<<" ";
}

bool ser(Node *node,int key){
    if(node==NULL) return false;
    if(node->data==key) return true;
    else if(node->data>key) return ser(node->left,key);
    else if(node->data<key) return ser(node->right,key);

    return false;
}
int main()
{
    create_tree();

    cout<<"Pre order:"<<endl;
    pre_order(root);
    cout<<endl;

    cout<<"In order:"<<endl;
    in_order(root);
    cout<<endl;

    cout<<"Post order:"<<endl;
    post_order(root);
    cout<<endl;

    if(ser(root,6))cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    return 0;
}
