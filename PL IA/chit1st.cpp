#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n], temp[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the number of rotations (k): ";
    cin >> k;
    k = k % n;

    cout << "Array after left rotation by " << k << " positions: ";
    for (int i = 0; i < n; ++i)
    {
        temp[i] = arr[(i + k) % n];
        cout << temp[i] << " ";
    }
    cout << endl;

    cout << "Array after right rotation by " << k << " positions: ";
    for (int i = 0; i < n; ++i)
    {
        temp[i] = arr[(i - k + n) % n];
        cout << temp[i] << " ";
    }
    cout << endl;

    return 0;
}