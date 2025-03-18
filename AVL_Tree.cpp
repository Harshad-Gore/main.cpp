#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int item)
    {
        data = item;
        left = right = NULL;
        height = 1;
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

    void deleteNode(int data)
    {
        root = deleteNode(root, data);
    }

    Node *search(int data)
    {
        return search(root, data);
    }

    void inorder()
    {
        inorder(root);
    }

    void preorder()
    {
        preorder(root);
    }

    void postorder()
    {
        postorder(root);
    }

    int height()
    {
        return height(root);
    }

private:
    int height(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
            return new Node(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data)
            return rotateRight(node);

        if (balance < -1 && data > node->right->data)
            return rotateLeft(node);

        if (balance > 1 && data > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && data < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node *deleteNode(Node *root, int data)
    {
        if (root == NULL)
            return root;

        if (data < root->data)
            root->left = deleteNode(root->left, data);
        else if (data > root->data)
            root->right = deleteNode(root->right, data);
        else
        {
            if ((root->left == NULL) || (root->right == NULL))
            {
                Node *temp = root->left ? root->left : root->right;

                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else
            {
                Node *temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == NULL)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);

        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);

        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
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

    void preorder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main()
{
    AVLTree avl;
    int choice;
    Node *result = NULL;
    do
    {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Print Height\n8. Exit\nEnter your choice: ";
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
            cout << "Enter data to delete: ";
            int delData;
            cin >> delData;
            avl.deleteNode(delData);
            break;
        case 3:
            cout << "Enter data to search: ";
            int searchData;
            cin >> searchData;
            result = avl.search(searchData);
            if (result != NULL)
                cout << "Data " << searchData << " found in the tree." << endl;
            else
                cout << "Data " << searchData << " not found in the tree." << endl;
            break;
        case 4:
            cout << "Inorder Traversal: ";
            avl.inorder();
            cout << endl;
            break;
        case 5:
            cout << "Preorder Traversal: ";
            avl.preorder();
            cout << endl;
            break;
        case 6:
            cout << "Postorder Traversal: ";
            avl.postorder();
            cout << endl;
            break;
        case 7:
            cout << "Height of the tree: " << avl.height() << endl;
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);
    return 0;
}