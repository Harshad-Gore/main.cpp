// C++ program to demonstate property 4 in exception
// handling.

#include <iostream>
using namespace std;
// This function signature is fine by the compiler, but not
// recommended. Ideally, the function should specify all
// uncaught exceptions and function signature should be
// "void fun(int *ptr, int x) throw (int *, int)"
void fun(int* ptr, int x)
{
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
    /* Some functionality */
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
