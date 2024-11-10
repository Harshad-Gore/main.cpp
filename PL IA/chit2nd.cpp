#include <iostream>
using namespace std;

int matrix1[10][10], matrix2[10][10], result[10][10];

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> rows >> cols;

    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix2[i][j];
        }
    }

    cout << "Addition of the two matrices:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Multiplication of the two matrices:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
