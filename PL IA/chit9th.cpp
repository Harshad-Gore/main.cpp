#include <iostream>
using namespace std;

struct Process
{
    int id;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    Process *next;
};

class Queue
{
public:
    Process *front;
    Process *rear;

    Queue()
    {
        front = rear = nullptr;
    }

    void enqueue(int id, int burstTime, int arrivalTime)
    {
        Process *temp = new Process();
        temp->id = id;
        temp->burstTime = burstTime;
        temp->arrivalTime = arrivalTime;
        temp->waitingTime = 0;
        temp->turnaroundTime = 0;
        temp->next = nullptr;
        if (rear == nullptr)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    Process *dequeue()
    {
        if (front == nullptr)
        {
            return nullptr;
        }
        Process *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        return temp;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

void calculateTimes(Queue &q)
{
    int currentTime = 0;
    Process *temp = q.front;
    while (temp != nullptr)
    {
        temp->waitingTime = max(0, currentTime - temp->arrivalTime);
        temp->turnaroundTime = temp->waitingTime + temp->burstTime;
        currentTime += temp->burstTime;
        temp = temp->next;
    }
}

void printProcesses(Queue &q)
{
    Process *temp = q.front;
    cout << "ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    while (temp != nullptr)
    {
        cout << temp->id << "\t" << temp->burstTime << "\t\t" << temp->arrivalTime << "\t\t" << temp->waitingTime << "\t\t" << temp->turnaroundTime << "\n";
        temp = temp->next;
    }
}

void fcfsScheduling(Queue &q)
{
    calculateTimes(q);
    cout << "FCFS Scheduling:\n";
    printProcesses(q);
}

void sjfScheduling(Queue &q)
{
    for (Process *i = q.front; i != nullptr; i = i->next)
    {
        for (Process *j = i->next; j != nullptr; j = j->next)
        {
            if (i->burstTime > j->burstTime)
            {
                swap(i->id, j->id);
                swap(i->burstTime, j->burstTime);
                swap(i->arrivalTime, j->arrivalTime);
            }
        }
    }
    calculateTimes(q);
    cout << "SJF Scheduling:\n";
    printProcesses(q);
}

int main()
{
    Queue q;
    q.enqueue(1, 6, 0);
    q.enqueue(2, 8, 1);
    q.enqueue(3, 7, 2);
    q.enqueue(4, 3, 3);

    fcfsScheduling(q);
    cout << "\n";

    Queue q2;
    q2.enqueue(1, 6, 0);
    q2.enqueue(2, 8, 1);
    q2.enqueue(3, 7, 2);
    q2.enqueue(4, 3, 3);

    sjfScheduling(q2);

    return 0;
}