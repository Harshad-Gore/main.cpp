#include <iostream>
using namespace std;
class B;

class A
{
private:
    static int counter;

public:
    A()
    {
        counter++;
    }

    static int getCounter()
    {
        return counter;
    }

    friend void showCounter(const B &b);
};

int A::counter = 0;

class B
{
private:
    int value;

public:
    B(int val) : value(val) {}

    friend void showCounter(const B &b);
};

void showCounter(const B &b)
{
    cout << "Value of B: " << b.value << endl;
    cout << "Number of A objects created: " << A::getCounter() << endl;
}

int main()
{
    A obj1, obj2, obj3;
    B objB(42);
    showCounter(objB);
    return 0;
}