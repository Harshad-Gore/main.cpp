#include <iostream>
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
class BinarySearchTree
{
private:
    Node *root;
    void inorderRecursion(Node *node)
    {
        if (node != NULL)
        {
            inorderRecursion(node->left);
            cout << node->data << " ";
            inorderRecursion(node->right);
        }
    }
    void inorderNonRecursion(Node *node)
    {
        Node *current = node;
        while (current != NULL)
        {
            while (current->left != NULL)
            {
                current = current->left;
            }
            cout << current->data << " ";
            if (current->right != NULL)
            {
                current = current->right;
            }
            else
            {
                break;
            }
        }
    }
    void preorderRecursive(Node *node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }
    void preorderNonRecursive(Node *node)
    {
        Node *current = node;
        while (current != NULL)
        {
            cout << current->data << " ";
            if (current->left != NULL)
            {
                current = current->left;
            }
            else
            {
                while (current != NULL && current->right == NULL)
                {
                    current = current->right;
                }
                if (current != NULL)
                {
                    current = current->right;
                }
            }
        }
    }
    void postorderRecursive(Node *node)
    {
        if (node != NULL)
        {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            cout << node->data << " ";
        }
    }
    void postorderNonRecursive(Node *node)
    {
        Node *current = node;
        Node *prev = NULL;
        while (current != NULL)
        {
            if (current->left == NULL && current->right == NULL)
            {
                cout << current->data << " ";
                current = NULL;
            }
            else
            {
                if (current->left != NULL && prev != current->left && prev != current->right)
                {
                    current = current->left;
                }
                else if (current->right != NULL && prev != current->right)
                {
                    current = current->right;
                }
                else
                {
                    cout << current->data << " ";
                    prev = current;
                    current = NULL;
                }
            }
        }
    }
    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            return new Node(data);
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        return node;
    }
    Node *search(Node *node, int data)
    {
        if (node == NULL || node->data == data)
        {
            return node;
        }
        if (data > node->data)
        {
            return search(node->right, data);
        }
        return search(node->left, data);
    }

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    void insert(int data)
    {
        root = insert(root, data);
    }
    void inorder(bool use_recursion)
    {
        cout << "Inorder Traversal: ";
        if (use_recursion)
        {
            inorderRecursion(root);
        }
        else
        {
            inorderNonRecursion(root);
        }
        cout << endl;
    }
    void preorder(bool use_recursion)
    {
        cout << "Preorder Traversal: ";
        if (use_recursion)
        {
            preorderRecursive(root);
        }
        else
        {
            preorderNonRecursive(root);
        }
        cout << endl;
    }
    void postorder(bool use_recursion)
    {
        cout << "Postorder Traversal: ";
        if (use_recursion)
        {
            postorderRecursive(root);
        }
        else
        {
            postorderNonRecursive(root);
        }
        cout << endl;
    }
    bool search(int data)
    {
        Node *result = search(root, data);
        if (result != NULL)
        {
            cout << "data " << data << " found in the tree." << endl;
            return true;
        }
        else
        {
            cout << "data " << data << " not found in the tree." << endl;
            return false;
        }
    }
};
int main()
{
    BinarySearchTree bst;
    int choice, value;
    bool use_recursion;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search Node\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            bst.insert(value);
            break;
        case 2:
            cout << "Use recursion ?: ";
            cin >> use_recursion;
            bst.inorder(use_recursion);
            break;
        case 3:
            cout << "Use recursion ?: ";
            cin >> use_recursion;
            bst.preorder(use_recursion);
            break;
        case 4:
            cout << "Use recursion ?: ";
            cin >> use_recursion;
            bst.postorder(use_recursion);
            break;
        case 5:
            cout << "Enter data to search: ";
            cin >> value;
            bst.search(value);
            break;
        case 6:
            cout << "Exited\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
