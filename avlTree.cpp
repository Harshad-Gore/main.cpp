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
    node *rotateRight(node *y)
    {
        if (y == NULL || y->left == NULL)
            return y;

        node *x = y->left;
        node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(calcHeight(y->left), calcHeight(y->right)) + 1;
        x->height = max(calcHeight(x->left), calcHeight(x->right)) + 1;

        return x;
    }
    node *rotateLeft(node *x)
    {
        if (x == NULL || x->right == NULL)
            return x;

        node *y = x->right;
        node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(calcHeight(x->left), calcHeight(x->right)) + 1;
        y->height = max(calcHeight(y->left), calcHeight(y->right)) + 1;

        return y;
    }
    node *insert(node *temp, int val)
    {
        if (temp == NULL)
            return new node(val);

        if (val < temp->data)
            temp->left = insert(temp->left, val);
        else if (val > temp->data)
            temp->right = insert(temp->right, val);
        else
            return temp; // Duplicate keys are not allowed

        temp->height = 1 + max(calcHeight(temp->left), calcHeight(temp->right)) + 1;

        int balance = balanceFactor(temp);

        // Left Left Case
        if (balance > 1 && val < temp->left->data)
            return rotateRight(temp);

        // Right Right Case
        if (balance < -1 && val > temp->right->data)
            return rotateLeft(temp);

        // Left Right Case
        if (balance > 1 && val > temp->left->data)
        {
            temp->left = rotateLeft(temp->left);
            return rotateRight(temp);
        }

        // Right Left Case
        if (balance < -1 && val < temp->right->data)
        {
            temp->right = rotateRight(temp->right);
            return rotateLeft(temp);
        }

        return temp;
    }
    void inorder(node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
    void preorder(node *temp)
    {
        if (temp == NULL)
            return;
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void postorder(node *temp)
    {
        if (temp == NULL)
            return;
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
    node *remove()
    {
        
    }
};

int main()
{
    return 0;
}