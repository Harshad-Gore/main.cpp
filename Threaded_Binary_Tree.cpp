#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    bool lthread, rthread;
    node(int val)
    {
        data = val;
        left = right = NULL;
        lthread = rthread = false;
    }
};

class threadedBinaryTree
{
    node *root;

public:
    threadedBinaryTree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        node *newNode = new node(val);
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        node *current = root, *parent = NULL;
        while (current != NULL)
        {
            parent = current;
            if (val < current->data)
            {
                if (current->lthread == false)
                    current = current->left;
                else
                    break;
            }
            else
            {
                if (current->rthread == false)
                    current = current->right;
                else
                    break;
            }
        }
        if (val < parent->data)
        {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->left = newNode;
            parent->lthread = false;
            newNode->lthread = true;
            newNode->rthread = true;
        }
        else
        {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->right = newNode;
            parent->rthread = false;
            newNode->rthread = true;
            newNode->lthread = true;
        }
    }
};

int main()
{
    threadedBinaryTree tbt;
    tbt.insert(10);
    tbt.insert(5);
    tbt.insert(15);
    return 0;
}