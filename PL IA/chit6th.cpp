#include <iostream>
using namespace std;
#define MAX 8

class Stack
{
    int row[MAX];
    int col[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int r, int c)
    {
        top++;
        row[top] = r;
        col[top] = c;
    }

    void pop()
    {
        if (!isEmpty())
        {
            top--;
        }
    }

    int getTopRow()
    {
        return row[top];
    }

    int getTopCol()
    {
        return col[top];
    }

    bool isSafe(int r, int c)
    {
        for (int i = 0; i <= top; i++)
        {
            if (col[i] == c || abs(row[i] - r) == abs(col[i] - c))
            {
                return false;
            }
        }
        return true;
    }
};

void solve8Queens()
{
    Stack s;
    int row = 0, col = 0;

    while (row < MAX)
    {
        while (col < MAX && !s.isSafe(row, col))
        {
            col++;
        }

        if (col < MAX)
        {
            s.push(row, col);
            row++;
            col = 0;
        }
        else
        {
            if (s.isEmpty())
                break;
            row = s.getTopRow();
            col = s.getTopCol() + 1;
            s.pop();
        }
    }

    if (row == MAX)
    {
        cout << "Solution found:" << endl;
        for (int i = 0; i < MAX; i++)
        {
            cout << "Queen " << i + 1 << " at: (" << i << ", " << s.getTopCol() << ")" << endl;
            s.pop();
        }
    }
    else
    {
        cout << "No solution found." << endl;
    }
}

int main()
{
    solve8Queens();
    return 0;
}
