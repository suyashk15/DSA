// Left view of a Binary Tree
// Logic: For every level, print only the first node (BFS)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int val)
{
    Node *root = new Node();
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void leftview(Node *root)
{
    if(!root) return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    bool isFirst = true;

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        if(temp==NULL)
        {
            if(q.size()==0) return;
            q.push(NULL);
            isFirst = true;
        }

        else
        {
            if(isFirst == true)
            {
                cout << temp->data << " ";
                isFirst = false;
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right); 
        } 
    }
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
    leftview(node);
}
