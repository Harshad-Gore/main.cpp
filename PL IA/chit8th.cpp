#include <iostream>
using namespace std;

#define SIZE 5

class PriorityQueue
{
    int arr[SIZE];
    int size;

public:
    PriorityQueue()
    {
        size = 0;
    }

    bool isFull()
    {
        return size == SIZE;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void insert(int value)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }

        int i = size++;
        while (i > 0 && arr[(i - 1) / 2] < value)
        {
            arr[i] = arr[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        arr[i] = value;
    }

    int deleteMax()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int maxVal = arr[0];
        arr[0] = arr[--size];
        heapify(0);

        return maxVal;
    }

    void heapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue (from high to low): ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(20);
    pq.insert(15);

    pq.printQueue();

    cout << "Processing patient with priority: " << pq.deleteMax() << endl;

    pq.printQueue();

    pq.insert(30);
    pq.insert(5);

    pq.printQueue();

    cout << "Processing patient with priority: " << pq.deleteMax() << endl;

    pq.printQueue();

    return 0;
}
