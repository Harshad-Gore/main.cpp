#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class HashTable {
private:
    Node *table[12];
public:
    HashTable() {
        for (int i = 0; i < 12; i++) table[i] = nullptr;
    }

    void insert(int key) {
        int index = key % 12;
        Node *newNode = new Node(key);
        if (!table[index]) {
            table[index] = newNode;
        } else {
            Node *temp = table[index];
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < 12; i++) {
            cout << i << ": ";
            Node *temp = table[i];
            while (temp) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable hashTable;
    int data[] = {10, 5, 4, 14, 15, 20, 11, 1, 6, 16, 36, 28};
    for (int i = 0; i < 12; i++) {
        hashTable.insert(data[i]);
    }
    hashTable.display();
    return 0;
}
