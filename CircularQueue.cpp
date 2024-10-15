#include <iostream>
using namespace std;
#define MAX 5
class CircularQueue
{
public:
    int front;
    int rear;
    int arr[MAX];
    CircularQueue()
    {
        front = rear = -1;
    }
    bool isFull()
    {
        if ((rear + 1) % MAX == front)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    void enQueue()
    {
        int data;
        if (isFull())
        {
            cout << "The queue is full." << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        cout << "Enter the value to add in the queue." << endl;
        cin >> data;
        arr[rear] = data;
    }
    void deQueue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty." << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "The queue is empty." << endl;
            return;
        }
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << "Data: " << arr[i] << endl;
            }
        }
        else
        {
            for (int i = front; i < MAX; i++)
            {
                cout << "Data: " << arr[i] << endl;
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << "Data: " << arr[i] << endl;
            }
        }
    }
};
void main()
{
    CircularQueue cq;
    int choice;
    char ch;
    do
    {
        cout << "1. Add data.\n2. Delete data.\n3. Display.\n4.Exit." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cq.enQueue();
            break;
        case 2:
            cq.deQueue();
            break;
        case 3:
            cq.display();
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
        cout << "Do you want to continue.(Y/n)" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}
