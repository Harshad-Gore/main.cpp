#include <iostream>
#include <cmath>
using namespace std;

#define MAX 4

class Sudoku
{
public:
    int row;
    int col;
    int val[MAX][MAX];

    Sudoku()
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                val[i][j] = 0;
            }
        }
    }

    void insert()
    {
        char c;
        do
        {
            cout << "This is a Sudoku of size 4x4. So enter valid values of row and column" << endl;
            cout << "Enter the row number: ";
            cin >> row;
            cout << "Enter the column number: ";
            cin >> col;
            cout << "Enter the value: ";
            cin >> val[row - 1][col - 1];
            cout << "You want to continue (y / n): ";
            cin >> c;
        } while (c == 'Y' || c == 'y');
    }

    void display()
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                cout << val[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "-----------------------\n";
    }

    bool solveSudoku(int row, int col)
    {
        if (row == MAX - 1 && col == MAX)
            return true;

        if (col == MAX)
        {
            col = 0;
            row++;
        }

        if (val[row][col] > 0)
            return solveSudoku(row, col + 1);

        for (int i = 1; i <= MAX; i++)
        {
            if (isValid(row, col, i))
            {
                val[row][col] = i;
                if (solveSudoku(row, col + 1))
                    return true;

                val[row][col] = 0;
            }
        }
        return false;
    }

    bool isValid(int row, int col, int number)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (val[row][i] == number)
                return false;
        }

        for (int i = 0; i < MAX; i++)
        {
            if (val[i][col] == number)
                return false;
        }

        int subgrid = sqrt(MAX);
        int r1 = row - (row % subgrid);
        int c1 = col - (col % subgrid);
        for (int i = r1; i < r1 + subgrid; i++)
        {
            for (int j = c1; j < c1 + subgrid; j++)
            {
                if (val[i][j] == number)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Sudoku s;
    s.insert();
    s.display();
    if (s.solveSudoku(0, 0))
    {
        s.display();
    }
    else
    {
        cout << "No solution exists" << endl;
    }
    return 0;
}