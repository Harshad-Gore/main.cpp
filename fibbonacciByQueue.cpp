#include <iostream>
using namespace std;
#define MAX 2 // Queue will hold only the last two Fibonacci numbers

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
        return (rear + 1) % MAX == front;
    }

    bool isEmpty()
    {
        return front == -1;
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
            front = (front + 1) % MAX;
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
            rear = (rear + 1) % MAX;
            data[rear] = x;
        }
    }

    int getFront()
    {
        if (!isEmpty())
        {
            return data[front];
        }
        return -1;
    }

    int getRear()
    {
        if (!isEmpty())
        {
            return data[rear];
        }
        return -1;
    }
};

void printFibonacci(int n)
{
    if (n <= 0)
    {
        cout << "Invalid input! n must be greater than 0." << endl;
        return;
    }

    Queue q;
    q.enqueue(0); // First Fibonacci number
    q.enqueue(1); // Second Fibonacci number

    cout << "Fibonacci series: ";
    for (int i = 0; i < n; i++)
    {
        int first = q.getFront();
        cout << first << " ";

        int second = q.getRear();
        int next = first + second;

        // Update the queue for the next iteration
        q.dequeue();
        q.enqueue(next);
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of Fibonacci numbers to print: ";
    cin >> n;

    printFibonacci(n);

    return 0;
}
