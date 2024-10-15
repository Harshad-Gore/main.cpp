#include <iostream>

using namespace std;

class Example
{
public:
    static int sCount;
    int nCount;

    Example(int count) : nCount(count)
    {
        sCount++;
    }

    static int getS()
    {
        return sCount;
    }

    int getN() const
    {
        return nCount;
    }
};

int Example::sCount = 0;

int main()
{
    Example obj1(10);
    Example obj2(20);
    Example obj3(30);

    cout << "Static Count: " << Example::getS() << endl;
    cout << "Normal Count of obj1: " << obj1.getN() << endl;
    cout << "Normal Count of obj2: " << obj2.getN() << endl;
    cout << "Normal Count of obj3: " << obj3.getN() << endl;

    return 0;
}
