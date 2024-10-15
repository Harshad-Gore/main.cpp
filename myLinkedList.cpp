#include <iostream>
using namespace std;

class node
{
    node *head;
    node *temp;

public:
    int data;
    node *next;
    node()
    {
        head = NULL;
    }
    void insert();
    void display();
    void insertAtStart();
    void insertAtEnd();
    void insertAtPos();
    void deleteAtStart();
    void deleteAtEnd();
    void deleteAtPos();
};
void node::insert()
{
    node *newPtr;
    char ch;
    do
    {
        newPtr = new node;
        cout << "Enter the data: ";
        cin >> newPtr->data;
        newPtr->next = NULL;

        if (head == NULL)
        {
            head = newPtr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newPtr;
        }
        cout << "Do you want to add more nodes.(Y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}
void node::display()
{
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void node::insertAtStart()
{
    node *newPtr;
    newPtr = new node;
    cout << "Enter the data: ";
    cin >> newPtr->data;
    newPtr->next = head;
    head = newPtr;
}
void node::insertAtEnd()
{
    node *newPtr;
    newPtr = new node;
    cout << "Enter the data: ";
    cin >> newPtr->data;
    newPtr->next = NULL;
    if (head == NULL)
    {
        head = newPtr;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newPtr;
    }
}
void node::insertAtPos()
{
    int loc;
    node *newPtr = new node;
    cout << "Enter data: ";
    cin >> newPtr->data;
    cout << "Enter the location to insert: ";
    cin >> loc;

    if (loc == 0) {
        newPtr->next = head;
        head = newPtr;
        return;
    }

    temp = head;
    for (int i = 0; i < loc - 1; ++i) {
        if (temp == NULL) {
            cout << "Position out of bounds" << endl;
            delete newPtr;
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        delete newPtr;
        return;
    }

    newPtr->next = temp->next;
    temp->next = newPtr;
}
void node::deleteAtStart()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void node::deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "List is empty: " << endl;
    }
    else
    {
        temp = head->next;
        node *curr = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            curr = curr->next;
        }
        curr->next =NULL;
        delete temp;
    }
}

int main()
{
    node list;
    list.insert();
    list.insertAtEnd();
    list.display();
    return 0;
}