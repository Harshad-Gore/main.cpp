#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    int height;

    node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class avlTree
{
    node *root;

public:
    avlTree()
    {
        root = NULL;
    }
    int calcHeight(node *temp)
    {
        if (temp == NULL)
            return 0;
        return temp->height;
    }
    int balanceFactor(node *temp)
    {
        if (temp == NULL)
            return 0;
        return calcHeight(temp->left) - calcHeight(temp->right);
    }
    node *rotateRight()
    {
        
    }
    node *insert(int val)
    {
    }
};

int main()
{
    return 0;
}