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
int main()
{
    sudoku su;
    su.takeInput();
    su.display();
    return 0;
}