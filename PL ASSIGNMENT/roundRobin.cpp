#include <iostream>
using namespace std;
#define MAX 4
class process
{
public:
    int processID;
    int burstTime;
    int remainingTime;
};
class processQueue
{
public:
    int front;
    int rear;
    int num;
    process arr[MAX];
    processQueue()
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
    void enQueue(process p)
    {
        if (isFull())
        {
            cout << "The queue is full." << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = p;
    }
    process deQueue()
    {
        process p;
        if (isEmpty())
        {
            cout << "The queue is empty." << endl;
        }
        else if (front == rear)
        {
            p = arr[front];
            front = rear = -1;
        }
        else
        {
            p = arr[front];
            front = (front + 1) % MAX;
        }
        return p;
    }
};
void RoundRobin(processQueue pq, int quantumTime)
{
    process p;
    int totalTime = 0;
    while (!pq.isEmpty())
    {
        p = pq.deQueue();
        if (p.remainingTime > quantumTime)
        {
            p.remainingTime -= quantumTime;
            totalTime += quantumTime;
            pq.enQueue(p);
            cout << "Process: " << p.processID << ". Scheduled for: " << quantumTime << "s , remaining time: " << p.remainingTime << "s" << endl;
        }
        else
        {
            cout << "Process: " << p.processID << " is completed in : " << totalTime + p.remainingTime << "s" << endl;
            totalTime += quantumTime;
            p.remainingTime = 0;
        }
    }
    cout << "Total Time: " << totalTime << "s" << endl;
}
int main()
{
    processQueue pq;
    cout << "Enter the number of elements in queue: ";
    cin >> pq.num;
    for (int i = 0; i < pq.num; i++)
    {
        cout << "Enter process ID and burst time for process " << i + 1 << ": ";
        cin >> pq.arr[i].processID >> pq.arr[i].burstTime;
        pq.arr[i].remainingTime = pq.arr[i].burstTime;
        pq.enQueue(pq.arr[i]);
    }
    int quantumTime;
    cout << "Enter the quantum time: ";
    cin >> quantumTime;
    RoundRobin(pq, quantumTime);
    return 0;
}