// Zigzag traversal of a binary tree
// Logic: Use 2 stacks
#include <bits/stdc++.h>
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

void zigzag(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);

    while(!s1.empty() or !s2.empty())
    {
        while(!s1.empty())
        {
            Node* temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
            if(temp->left) s2.push(temp->left);
            if(temp->right) s2.push(temp->right);
        }

        while(!s2.empty())
        {
            Node* temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
            if(temp->right) s1.push(temp->right);
            if(temp->left) s1.push(temp->left);
        }
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
    zigzag(node);
}

