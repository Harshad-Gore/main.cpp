#include <iostream>
using namespace std;
#define size 10
class cir_q
{
    public:
    int front;
    int rear;
    int arr[size];
    cir_q()
    {
        front = -1;
        rear = -1;
    }
    bool isfull()
    {
        if ((rear + 1) % size == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isempty()
    {
        if (front == -1 &&rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue()
    {
        int val;
        char ch;
        do
        {
            if (isfull())
            {
                cout << "Queue is full. Can not insert more elements";
            }
            else if (front == -1)
            {
                front = 0;
                rear = 0;
                cout << "Enter the element";
                cin >> val;
                arr[rear] = val;
            }
            else
            {

                cout << "Enter the element";
                cin >> val;
                rear = (rear + 1) % size;
                arr[rear] = val;
            }
            cout << "Do you want to add more elements(Y/N)";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }
    void dequeue()
    {

        char ch;
        do
        {
            if (isempty())
            {
                cout << "Queue is empty. Can not delete more elements";
            }
            else if (rear == front)
            {
                rear = -1;
                front = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            cout << "Do you want to add more elements(Y/N)";
            cin >> ch;
        }while (ch == 'y' || ch == 'Y');
    }
    
};
int main()
{
    cir_q c;
    c.enqueue();
    c.dequeue();
    return 0;
}