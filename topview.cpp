// Logic: Use map and level order traversal. Assign hd and print only first ele of a hd

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

void topview(Node *root)
{
    if(!root) return;
    queue<pair<Node *,int>> q;
    q.push({root,0});
    map<int, int> m;

    while(!q.empty())
    {
        pair<Node *,int> p =q.front();
        q.pop();
        Node *temp = p.first;
        int hd = p.second;
        // Only enter the first element of a HD
        // For bottom view, remove if condition. Last element of hd will be stored
        if(m.find(hd)==m.end()) m[hd] = temp->data;

        if(temp->left) q.push({temp->left,hd-1});
        if(temp->right) q.push({temp->right,hd+1});
    }

    for(auto it:m)
    {
        cout << it.second << " ";
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
    topview(node);
}
