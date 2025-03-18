#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        right = left = NULL;
    }
};
class BinarySearchTree
{
    node *insert(node *root, int data)
    {
        if (root == NULL)
        {
            return new node(data);
        }
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
    node *search(node *root, int data)
    {
        if (root == NULL || root->data == data)
        {
            return root;
        }
        if (data < root->data)
        {
            return search(root->left, data);
        }
        return search(root->right, data);
    }
    
};
int main()
{
    return 0;
}