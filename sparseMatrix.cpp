#include <iostream>
#define MAX 50
using namespace std;

class sparseMatrix
{
    int sp[MAX][3];
    int len;

public:
    sparseMatrix(int row, int col, int l)
    {
        sp[0][0] = row;
        sp[0][1] = col;
        sp[0][2] = l;
        len = 0;
    }

    void insert(int rowValue, int colValue, int value)
    {
        if (rowValue >= sp[0][0] || colValue >= sp[0][1])
        {
            cout << "Invalid Number" << endl;
        }
        else
        {
            sp[len + 1][0] = rowValue;
            sp[len + 1][1] = colValue;
            sp[len + 1][2] = value;
            len++;
        }
    }

    void display()
    {
        cout << "row\tcol\tvalue" << endl;
        for (int i = 1; i <= len; i++)
        {
            cout << sp[i][0] << "\t" << sp[i][1] << "\t" << sp[i][2] << endl;
        }
    }
};

int main()
{
    int r1, c1, l1;
    cout << "Enter the number of rows of Sparse Matrix: ";
    cin >> r1;
    cout << "Enter the number of columns of Sparse Matrix: ";
    cin >> c1;
    cout << "Enter the number of non-zero values in Matrix: ";
    cin >> l1;

    sparseMatrix s1(r1, c1, l1);

    for (int i = 0; i < l1; i++)
    {
        int row, col, value;
        cout << "Enter row Number: ";
        cin >> row;
        cout << "Enter column Number: ";
        cin >> col;
        cout << "Enter Value: ";
        cin >> value;
        s1.insert(row, col, value);
    }

    s1.display();
    return 0;
}
/*void transpose(sparse s1)*/
