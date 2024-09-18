#include <iostream>
using namespace std;

int main() {
    int *ptr = NULL;
    cout << *ptr << endl;
    delete ptr;
    cout << "The NULL pointer is deleted." << endl;
    return 0;
}
