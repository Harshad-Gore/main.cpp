#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
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

    void create();
    void print();
    void mergeAlternate(DoublyLinkedList &list2);
    void sort();
};

void DoublyLinkedList::create()
{
    Node *temp;
    char choice;
    do
    {
        temp = new Node;
        cout << "Enter data: ";
        cin >> temp->data;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        cout << "Do you want to add more nodes (Y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void DoublyLinkedList::print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DoublyLinkedList::mergeAlternate(DoublyLinkedList &list2)
{
    Node *p = head;
    Node *q = list2.head;

    while (p != NULL && q != NULL)
    {
        Node *pNext = p->next;
        Node *qNext = q->next;

        p->next = q;
        q->prev = p;
        if (pNext != NULL)
        {
            q->next = pNext;
            pNext->prev = q;
        }
        else
        {
            q->next = NULL;
        }

        p = pNext;
        q = qNext;
    }
    list2.head = NULL;
}

void DoublyLinkedList::sort()
{
    if (head == NULL)
        return;
    bool swapped;
    Node *ptr;
    do
    {
        swapped = false;
        ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->data > ptr->next->data)
            {
                swap(ptr->data, ptr->next->data);
                swapped = true;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

int main()
{
    DoublyLinkedList list1, list2;
    cout << "Create first list:" << endl;
    list1.create();
    cout << "Create second list:" << endl;
    list2.create();

    list1.mergeAlternate(list2);
    cout << "Merged list at alternate positions: ";
    list1.print();

    list1.sort();
    cout << "Sorted merged list: ";
    list1.print();

    return 0;
}
