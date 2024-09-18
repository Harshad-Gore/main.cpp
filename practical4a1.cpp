#include <iostream>
using namespace std;

int main()
{
    int *arr, max_num, i;

    cout << "Enter total number of elements." << endl;
    cin >> max_num;

    arr = new int[max_num];

    cout << "Enter the numbers:" << endl;
    for (i = 0; i < max_num; i++)
    {
        cout << "Number " << i + 1 << " is:" << endl;
        cin >> arr[i];
    }
    cout << "Numbers are:" << endl;
    for (i = 0; i < max_num; i++)
    {
        cout << arr[i] << "\t";
    }
    delete[] arr;
    return 0;
}