#include <iostream>
using namespace std;
#define MAX 4

class sudoku
{
public:
    int row, col, val;
    int grid[MAX][MAX];
    sudoku()
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                grid[i][j] = 0;
            }
        }
    }

    void takeInput()
    {
        char ch;
        do
        {
            cout << "Enter the row number." << endl;
            cin >> row;
            cout << "Enter the column number." << endl;
            cin >> col;
            cout << "Enter the data." << endl;
            cin >> val;

            if (row >= 0 && row < MAX && col >= 0 && col < MAX)
            {
                grid[row - 1][col - 1] = val;
            }
            else
            {
                cout << "Invalid row or column number." << endl;
            }

            cout << "Do you want to add more values.(Y/n)" << endl;
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }
    void display()
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
};
bool isSafe(int grid[MAX][MAX], int row, int col, int num)
{
    for (int x = 0; x < MAX; x++)
    {
        if (grid[row][x] == num || grid[x][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[MAX][MAX], int row, int col)
{
    if (row == MAX - 1 && col == MAX)
    {
        return true;
    }
    if (col == MAX)
    {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
    {
        return solveSudoku(grid, row, col + 1);
    }
    for (int num = 1; num <= MAX; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
            {
                return true;
            }
        }
        grid[row][col] = 0;
    }
    return false;
}

int main()
{
    sudoku su;
    su.takeInput();
    if (solveSudoku(su.grid, 0, 0))
    {
        su.display();
    }
    else
    {
        cout << "No solution exists" << endl;
    }
    return 0;
}