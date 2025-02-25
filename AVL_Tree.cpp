#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int item)
    {
        data = item;
        left = right = NULL;
    }
};

class AVLTree
{
private:
    Node *root;

public:
    AVLTree() : root(NULL) {}

    void insert(int data)
    {
        root = insert(root, data);
    }

    Node *search(int data)
    {
        return search(root, data);
    }

    void inorder()
    {
        inorder(root);
    }

    int height()
    {
        return height(root);
    }

private:
    Node *insert(Node *node, int data)
    {
        if (node == NULL)
            return new Node(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        return node;
    }

    Node *search(Node *node, int data)
    {
        if (node == NULL || node->data == data)
            return node;
        if (data > node->data)
            return search(node->right, data);
        return search(node->left, data);
    }

    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    int height(Node *node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }

    int getBalance(Node *node)
    {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }
};

int main()
{
    AVLTree avl;
    int choice;
    Node *result = NULL;
    do
    {
        cout << "1. Insert\n2. Search\n3. Inorder Traversal\n4. Print Height\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            int data;
            cin >> data;
            avl.insert(data);
            break;
        case 2:
            cout << "Enter data to search: ";
            int searchData;
            cin >> searchData;
            result = avl.search(searchData);
            if (result != NULL)
                cout << "data " << searchData << " found in the tree." << endl;
            else
                cout << "data " << searchData << " not found in the tree." << endl;
            break;
        case 3:
            cout << "Inorder Traversal: ";
            avl.inorder();
            cout << endl;
            break;
        case 4:
            cout << "Height of the tree: " << avl.height() << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}