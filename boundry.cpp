// IMP Q: Boundary Traversal of a BT
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int val)
{
    Node *root = new Node();
    root->data = val;
    root->left = root->right = NULL;
    return root;
}

void lb(Node *root, vector<int> &v) // lb = left boundary
{
    if(!root) return;
    if(root->left or root->right) v.push_back(root->data); //To avoid leaf nodes
    if(root->left) lb(root->left,v);
    else if(root->right) lb(root->right,v);
}

void leafnodes(Node *root, vector<int> &v)
{
    if(!root) return;
    if(root->left) leafnodes(root->left, v);
    if(!root->left and !root->right) v.push_back(root->data);
    if(root->right) leafnodes(root->right, v);
}

void rb(Node *root, vector<int> &v) // rb = right boundary
{
    if(!root) return;
    if(root->right) rb(root->right,v);
    else if(root->left) rb(root->left,v);
    if(root->left or root->right) v.push_back(root->data); 
    //This is last step as we want traversal from bottom to top on the right side   
}

void boundary(Node *root, vector<int> &v)
{
    lb(root,v);
    leafnodes(root,v);
    rb(root,v);
    for(auto i:v) cout << i << " ";
}

int main()
{
    Node *node = createNode(5);
    node->right = createNode(6);
    node->left = createNode(7);
    node->right->left = createNode(8);
    node->right->right = createNode(9);
    node->left->left = createNode(4);
    node->left->right = createNode(3);
    vector<int> v;
    boundary(node,v);
}
