#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    node *left, *right;
    int data;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

node *search(node *root, int val)
{
    if (root == NULL || root->data == val)
    {
        return root;
    }
    else if (val < root->data)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        cout << current->data << " ";
        q.pop();
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
}

// delete a node from the BST
node *deleteNode(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        node *temp = root->right;
        while (temp && temp->left != NULL)
        {
            temp = temp->left;
        }

        // copy the inorder successor's content to this node
        root->data = temp->data;

        // delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



int main()
{
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    if(search(root, 0) != NULL)
    {
        cout << "Node found!" << endl;
    }
    else
    {
        cout << "Node not found!" << endl;
    }

    return 0;
}