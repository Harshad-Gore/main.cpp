#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void merge(DoublyLinkedList &list2)
    {
        if (head == NULL)
        {
            head = list2.head;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = list2.head;
        if (list2.head != NULL)
        {
            list2.head->prev = temp;
        }
    }
};

int main()
{
    DoublyLinkedList list1, list2;
    int n, value;

    cout << "Enter the number of elements for the first list: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter value: ";
        cin >> value;
        list1.insert(value);
    }

    cout << "Enter the number of elements for the second list: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter value: ";
        cin >> value;
        list2.insert(value);
    }

    list1.merge(list2);

    cout << "Merged doubly linked list: ";
    list1.print();

    return 0;
}
