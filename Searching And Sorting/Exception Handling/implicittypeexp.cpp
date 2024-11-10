//// C++ program to demonstate property 2: Implicit type
/// conversion doesn't happen for primitive types.
// in exception handling.

#include <iostream>
using namespace std;

int main()
{
    try {
        throw 'a';
    }
    catch (int x) {
        cout << "Caught " << x;
    }
    catch (...) {
        cout << "Default Exception\n";
    }
    return 0;
}
