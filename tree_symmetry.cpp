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
    root->right = root->left = NULL;
    return root;
}

// Check if 2 binary trees are identical
bool isIdentical(Node *r1, Node *r2)
{
    if(r1==NULL and r2==NULL) return true;
    if(r1==NULL or r2==NULL) return false;
    if(r1->data != r2->data) return false;
    return (isIdentical(r1->left,r2->left) and isIdentical(r1->right, r2->right));
}

// Check for a subtree of binary tree
// Logic: Find root of small tree in big one by level order and use isIdentical then
bool isSubtree(Node *r1, Node *r2)
{
    if(!r1 or !r2) return false;
    queue<Node *> q;
    q.push(r1);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp->data == r2->data and isIdentical(temp,r2)) return true;

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return false;
}

// Check is 2 binary trees are mirror images
bool isMirror(Node *r1, Node *r2)
{
    if(!r1 and !r2) return true;
    if(!r1 or !r2) return false;
    if(r1->data != r2->data) return false;
    return (isMirror(r1->left,r2->right) and isMirror(r1->right,r2->left));
}

//Invert a binary tree
void invert(Node *root)
{
    if(!root) return;
    //Swap right and left
    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;
    invert(root->left);
    invert(root->right);
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
    node->right->left->left = createNode(2);
    cout << isIdentical(node,node);
    invert(node);
}
