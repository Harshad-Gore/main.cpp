#include <iostream>
using namespace std;
#define MAX 5
class Queue
{
    int data[MAX];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }
    bool isFull()
    {
        if (rear == MAX - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void dequeue()
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
            front++;
        }
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "The queue is full." << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            data[rear] = x;
        }
        else
        {
            data[++rear] = x;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "The queue is empty." << endl;
        }
        else
        {
            for (int i = 0; i < MAX; i++)
            {
                if (i >= front && i <= rear)
                {
                    cout << i + 1 << ".Data:" << data[i] << endl;
                }
            }
        }
    }
};
int main()
{
    Queue q;
    int data = 0;
    for (int i = 0; i < MAX; i++)
    {
        cout << i + 1 << ".Data:" << endl;
        cin >> data;
        q.enqueue(data);
    }
    q.dequeue();
    q.dequeue();
    q.display();
}