#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* ptr = &a;
    int& ref = a;

    cout << "Value of a: " << a << endl;
    cout << "Value of *ptr: " << *ptr << endl;
    cout << "Value of ref: " << ref << endl;

    *ptr = 20;
    cout << "After changing *ptr to 20:" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of ref: " << ref << endl;

    ref = 30;
    cout << "After changing ref to 30:" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of *ptr: " << *ptr << endl;

    int* dynamicInt = new int;
    *dynamicInt = 40;

    cout << "Value of dynamically allocated int: " << *dynamicInt << endl;

    delete dynamicInt;

    return 0;
}