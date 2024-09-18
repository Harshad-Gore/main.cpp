#include <iostream>
using namespace std;

int main() {
    int *ptr = new int;
    int *ptr2 = new int(10);

    cout << "The value of the ptr is: "<< *ptr << endl;
    cout << "The value of the ptr2 is: "<< *ptr2 << endl;

    delete ptr2,ptr;
    return 0;
}