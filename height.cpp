// Height of a binary tree

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;
};

Node* createNode(int val)
{
    Node* root = new Node();
    root->data = val;
    root->right = root->left = NULL;
    return root;
}

int height(Node* root)
{
    if(root==NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    Node* node = createNode(5);
    node->right = createNode(6);
    node->left = createNode(7);
    node->right->left = createNode(8);
    node->right->right = createNode(9);
    node->left->left = createNode(4);
    node->left->right = createNode(3);
    cout << height(node);
}