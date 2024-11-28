#include <iostream>
using namespace std;

#define SIZE 20

class Node
{
public:
    int key;
    Node *next;

    Node(int k)
    {
        key = k;
        next = NULL;
    }
};

class HashTable
{
public:
    Node *table[SIZE];

    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    int hashFunction(int key)
    {
        return key % SIZE;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key);
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            Node *temp = table[index];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        Node *temp = table[index];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Index " << i << ": ";
            Node *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);

    ht.display();

    cout << "Search 30: " << (ht.search(30) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (ht.search(100) ? "Found" : "Not Found") << endl;

    return 0;
}