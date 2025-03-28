#include <iostream>
using namespace std;

void fun(int* ptr, int x) throw (int*, int) 
{
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
}

int main()
{
    try {
        fun(NULL, 0);
    }
    catch (...) {
        cout << "Caught exception from fun()";
    }
    return 0;
}
