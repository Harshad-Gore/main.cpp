#include <iostream>
using namespace std;
#define SIZE 5
class Queue
{
    int front, rear;
    int arr[SIZE];
    Queue()
    {
        front = rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    void insertAtFront(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            cout << "The Queue is full." << endl;
        }
        else
        {
            front--;
            x = arr[front];
        }
    }
    void insertAtRear(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            x = arr[rear];
        }
        else if (rear = SIZE -1)
        {
            cout << "Cannot insert at rear." << endl;
        }
        else
        {
            rear++;
            x = arr[rear];
        }
    }
    int deleteFront(int x)
    {
        if (isEmpty())
        {
            cout << "The queue is empty." << endl;
            return;
        }
        else if (front == rear)
        {
            x = arr[front];
            front = rear = -1;
        }
        else
        {
            x = arr[rear];
            rear--;
        }
        return x;
    }
};
int main() {
    
    return 0;
}