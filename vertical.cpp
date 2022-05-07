// Vertical trevaersal of a binary tree
// Logic: Assign -ve and +ve horizontal dist from root and store in map.

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

void vertical(Node* root)
{
    queue<pair<Node*, int>> q;
    map<int,vector<int>> mp;
    q.push({root,0});

    while(!q.empty())
    {
        pair<Node*, int> p = q.front();
        q.pop();

        Node* temp = p.first;
        int hd = p.second;
        mp[hd].push_back(temp->data);

        if(temp->left) q.push({temp->left, hd-1});
        if(temp->right) q.push({temp->right, hd+1});
    }

    for(auto it: mp)
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
    vertical(node);
}