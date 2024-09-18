#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter the number of rows of the array:" << endl;
    cin >> rows;
    cout << "Enter the number of columns of the array:" << endl;
    cin >> cols;

    int arr1[rows][cols];
    int arr2[rows][cols];
    int result[rows][cols];

    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            cout << "A["<<i+1<<","<<j+1<<"]"<< endl;
            cin >> arr1[i][j];
        }
    }

    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "B["<<i+1<<","<<j+1<<"]"<< endl;
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    cout << "Result is:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << result[i][j]<< " ";
        }
        cout << endl;
    }
    cout << "After sorting:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr1[i][j]){

            }
        }
        cout << endl;
    }
    return 0;
}
