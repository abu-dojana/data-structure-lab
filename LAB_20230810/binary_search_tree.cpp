/*
Binary Search Tree
==================
1. Inserting Value Function
2. deleting Value Function.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *root = NULL;

void insert(int val)
{
    Node *temp;
    temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        Node *curr_node = root;
        Node *prev_node = root;

        while (curr_node != NULL)
        {
            if (curr_node->data > temp->data)
            {
                prev_node = curr_node;
                curr_node = curr_node->left;
            }
            else
            {
                prev_node = curr_node;
                curr_node = curr_node->right;
            }
        }

        if (prev_node->data > temp->data)
        {

            prev_node->left = temp;
        }
        else
        {

            prev_node->right = temp;
        }
    }
}

/*
Delete a new node from the tree:
1. Node to be deleted is a leaf node.
2. Node to be deleted has only one child.
3. Node to be deleted has two children.
*/

void delete_node(int val)
{
    Node *temp = root, *parent = NULL;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            break;
        }
        parent = temp;
        if (temp->data > val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    // 1. Node to be deleted is a leaf node.
    if (temp->left == NULL && temp->right == NULL)
    {
        if (parent == NULL)
        {
            root = NULL;
        }
        else if (parent->left == temp)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        delete temp;
    }

    // 2. Node to be deleted has only one child.
    else if (temp->left == NULL || temp->right == NULL)
    {
        Node *child = (temp->left != NULL) ? temp->left : temp->right;
        if (parent == NULL)
        {
            root = child;
        }
        else if (parent->left == temp)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        delete temp;
    }

    // 3. Node to be deleted has two children.
    else
    {
        Node *succ = temp->right;
        parent = NULL;
        while (succ->left != NULL)
        {
            parent = succ;
            succ = succ->left;
        }
        temp->data = succ->data;
        if (parent != NULL)
        {
            parent->left = succ->right;
        }
        else
        {
            temp->right = succ->right;
        }
        delete succ;
    }
}

// inorder
void inorder(Node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

// // inorder sorting
// void inorder_sorting(Node *temp)
// {
//     if (temp != NULL)
//     {
//         inorder_sorting(temp->left);
//         inorder_sorting
//         inorder_sorting(temp->right);
//     }
// }

int main()
{
    cout << "Binary Search Tree" << endl;
    cout << "==================" << endl;
    cout << "1. Inserting Value Function" << endl;
    insert(10);
    insert(20);
    insert(30);
    inorder(root);
    cout << endl;
    cout << "2. deleting Value Function." << endl;
    delete_node(20);
    inorder(root);
}
