#include <iostream>
#include <bits/stdc++.h>
#define SPACE 10

using namespace std;

class Treenode{
    public:
        int value;
        Treenode *left;
        Treenode *right;

        Treenode()          // Default Constructor
        {
            value = 0;
            left = NULL;
            right = NULL;
        }
        Treenode(int v)     // Parameterized constructor
        {
            value = v;
            left = NULL;
            right = NULL;

        }
};

class BST{
    public:
        Treenode *root;

        BST()
        {
            root = NULL;
        }

        bool isEmpty()
        {
            if(root==NULL)
                return true;
            else
                return false;
        }

        void insertNode(Treenode *new_node)
        {
            if(root == NULL)
            {
                root = new_node;
            }
            else
            {
                Treenode *temp = root;
                while(temp != NULL)
                {
                    if(new_node->value == temp->value)
                    {
                        cout << "Value Already Exits !"<<endl;
                        return;
                    }
                    else if((new_node->value < temp->value) && (temp->left==NULL))
                    {
                        temp->left = new_node;
                        cout << "Value Inserted" <<endl;
                        break;
                    }
                    else if(new_node->value < temp->value)
                    {
                        temp = temp->left;
                    }
                    else if((new_node->value > temp->value) && (temp->right==NULL))
                    {
                        temp->right = new_node;
                        cout << "Value Inserted" <<endl;
                        break;
                    }
                    else if(new_node->value > temp->value)
                    {
                        temp = temp->right;
                    }
                }

            }
        }
};

int main()
{
    BST obj;
    int option,val;
    cin >> option;

    Treenode *new_node = new Treenode();
    
    do
    {
        cout << "What operation do you want to perform ?"
        << " Select option number. Enter 0 to exit" << endl;

        cout << "1. Insert a Node " << endl;
        cout << "2. Search a Node " << endl;
        cout << "3. Delete a Node " << endl;
        cout << "4. Print BST values " << endl;
        cout << "5. Clear Screen " << endl;
        cout << "0. Exit Program " << endl;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Insert" <<endl;
            cout << "Enter value to be inserted";
            cin >> val;
            new_node->value = val;
            obj.insertNode(new_node);
            cout << endl;
            break;
        case 2:
            cout << "Search" <<endl;
            // Search code
            break;
        case 3:
            cout << "Delete" <<endl;
            // Deletion code
            break;
        case 4:
            cout << "Print" <<endl;
            // Printing code
            break;
        case 5:
            cout << "Clear" <<endl;
            //  code
            break;
        default:
            cout << "Enter a valid option" << endl;
        }

    } while (option != 0);
    

}