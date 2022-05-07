// Diagonal traversal of binary tree
// Que: If any 2 nodes are same level, the one which comes first in PREORDER is first
// Logic: From a node, anything at right is at same level and at left is +1 level


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

//Its given PREORDER in question, so function modified accordingly
void diagonal(Node* root, map<int,vector<int>> &mp, int dd)
{
    if(root==NULL) return;
    mp[dd].push_back(root->data);
    if(root->left) diagonal(root->left, mp, dd+1);
    if(root->right) diagonal(root->right, mp, dd);
}

void print_diagonal(Node* root)
{
    map<int,vector<int>> mp;
    int dd = 0;
    diagonal(root, mp, dd);

    for(auto it:mp)
    {
        vector<int> v = it.second;
        for(auto i:v) cout << i << " ";
    }
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
    print_diagonal(node);
}