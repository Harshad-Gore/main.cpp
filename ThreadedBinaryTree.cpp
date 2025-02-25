#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    bool leftThread, rightThread;

    Node(int item) {
        data = item;
        left = right = NULL;
        leftThread = rightThread = false;
    }
};

class ThreadedBinarySearchTree {
private:
    Node *root;

    Node *insert(Node *node, int data) {
        if (node == NULL) return new Node(data);
        if (data < node->data) {
            if (node->leftThread) {
                Node *temp = new Node(data);
                temp->left = node->left;
                temp->right = node;
                node->left = temp;
                node->leftThread = false;
            } else {
                node->left = insert(node->left, data);
            }
        } else if (data > node->data) {
            if (node->rightThread) {
                Node *temp = new Node(data);
                temp->right = node->right;
                temp->left = node;
                node->right = temp;
                node->rightThread = false;
            } else {
                node->right = insert(node->right, data);
            }
        }
        return node;
    }

    Node *search(Node *node, int data) {
        if (node == NULL || node->data == data) return node;
        if (data > node->data) return search(node->right, data);
        return search(node->left, data);
    }

    void inorder(Node *node) {
        Node *current = node;
        while (current != NULL) {
            while (current->left != NULL && !current->leftThread) current = current->left;
            cout << current->data << " ";
            while (current->rightThread) {
                current = current->right;
                cout << current->data << " ";
            }
            current = current->right;
        }
    }

    void preorder(Node *node) {
        Node *current = node;
        while (current != NULL) {
            cout << current->data << " ";
            if (!current->leftThread) current = current->left;
            else if (!current->rightThread) current = current->right;
            else {
                while (current != NULL && current->rightThread) current = current->right;
                if (current != NULL) current = current->right;
            }
        }
    }

    void postorder(Node *node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    ThreadedBinarySearchTree() { root = NULL; }

    void insert(int data) { root = insert(root, data); }
    void inorder() { cout << "Inorder Traversal: "; inorder(root); cout << endl; }
    void preorder() { cout << "Preorder Traversal: "; preorder(root); cout << endl; }
    void postorder() { cout << "Postorder Traversal: "; postorder(root); cout << endl; }
    bool search(int data) {
        Node *result = search(root, data);
        if (result != NULL) {
            cout << "data " << data << " found in the tree." << endl;
            return true;
        } else {
            cout << "data " << data << " not found in the tree." << endl;
            return false;
        }
    }
};

int main() {
    ThreadedBinarySearchTree tbst;
    int choice, value;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search Node\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tbst.insert(value);
                break;
            case 2:
                tbst.inorder();
                break;
            case 3:
                tbst.preorder();
                break;
            case 4:
                tbst.postorder();
                break;
            case 5:
                cout << "Enter data to search: ";
                cin >> value;
                tbst.search(value);
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
