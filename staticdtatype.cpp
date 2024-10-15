#include <iostream>
using namespace std;
void incrementAndPrint()
{
    static int x = 0;
    int y = 0;

    ++x;
    ++y;
    cout << "X = " << x;
    cout << ", Y = " << y << endl;
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        incrementAndPrint();
    }
    return 0;
}