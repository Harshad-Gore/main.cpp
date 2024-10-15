#include <iostream>
using namespace std;

class node
{
public:
    string data;
    node *next;
    node *prev;
    node()
    {
        prev = next = NULL;
    }
};

class deQueue
{
public:
    node *front;
    node *rear;

    deQueue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        return false;
    }
    void enqueue(string value)
    {
        node *newNode = new node();
        newNode->data = value;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }
    void insertAtFront(node *asap)
    {
        cout << "Enter the data." << endl;
        cin >> asap->data;
        if (isEmpty())
        {
            front = rear = asap;
        }
        else
        {
            front->prev = asap;
            asap->next = front;
            front = asap;
        }
    }
    void insertAtRear(node *asap)
    {
        cout << "Enter the data." << endl;
        cin >> asap->data;
        if (isEmpty())
        {
            front = rear = asap;
        }
        else
        {
            rear->next = asap;
            asap->prev = rear;
            rear = asap;
        }
    }
    void delAtFront()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty." << endl;
        }
        else if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            node *temp;
            temp = front;
            front = front->next;
            front->prev = NULL;
            delete temp;
        }
    }
    void delAtRear()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty." << endl;
        }
        else if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            node *temp;
            temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete temp;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty." << endl;
        }
        else
        {
            node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    string value;
    node sl;
    deQueue dq;
    cout << "Enter the data." << endl;
    cin >> value;
    dq.enqueue(value);
    node* newNodeFront = new node();
    dq.insertAtFront(newNodeFront);
    node* newNodeRear = new node();
    dq.insertAtRear(newNodeRear);
    dq.delAtFront();
    dq.delAtRear();
    dq.display();
    return 0;
}