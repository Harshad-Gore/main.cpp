#include <iostream>
using namespace std;

class deQueue
{
private:
    int front, rear, size;
    string *arr;

public:
    deQueue(int s)
    {
        front = -1;
        rear = 0;
        size = s;
        arr = new string[s];
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void insertAtFront(string key)
    {
        if (isFull())
        {
            cout << "Overflow\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
            front = size - 1;
        else
            front = front - 1;

        arr[front] = key;
    }

    void insertAtRear(string key)
    {
        if (isFull())
        {
            cout << " Overflow\n ";
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1)
            rear = 0;
        else
            rear = rear + 1;

        arr[rear] = key;
    }

    void delAtFront()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }

    void delAtRear()
    {
        if (isEmpty())
        {
            cout << " Underflow\n";
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty." << endl;
            return;
        }

        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the deque: ";
    cin >> size;
    deQueue q1(size), q2(size);
    int choice;
    int ch2, ch3;
    string value;

    do
    {
        cout << "1.Input restricted.\n2.Output Restricted.\n3.Exit." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                cout << "1.Insert at rear.\n2.Delete front.\n3.Delete rear.\n4.Display.\n5.Exit." << endl;
                cin >> ch2;
                switch (ch2)
                {
                case 1:
                    cout << "Enter the data." << endl;
                    cin >> value;
                    q1.insertAtRear(value);
                    break;

                case 2:
                    q1.delAtFront();
                    break;

                case 3:
                    q1.delAtRear();
                    break;

                case 4:
                    q1.display();
                    break;

                case 5:
                    break;

                default:
                    cout << "Enter a valid choice." << endl;
                    break;
                }

            } while (ch2 != 5);
            break;

        case 2:
            do
            {
                cout << "1.Insert at front.\n2.Delete front.\n3.Delete rear.\n4.Display.\n5.Exit." << endl;
                cin >> ch3;
                switch (ch3)
                {
                case 1:
                    cout << "Enter the data." << endl;
                    cin >> value;
                    q2.insertAtFront(value);
                    break;

                case 2:
                    q2.delAtFront();
                    break;

                case 3:
                    q2.delAtRear();
                    break;

                case 4:
                    q2.display();
                    break;

                case 5:
                    break;

                default:
                    cout << "Enter a valid choice." << endl;
                    break;
                }

            } while (ch3 != 5);
            break;

        case 3:
            break;

        default:
            cout << "Enter a valid choice." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}
