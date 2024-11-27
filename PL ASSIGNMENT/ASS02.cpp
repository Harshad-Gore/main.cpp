#include <iostream>
#define max 20
using namespace std;

class Sparse_mat
{
    int data[max][3];
    int len;

public:
    Sparse_mat(int r, int c, int l)
    {
        data[0][0] = r;
        data[0][1] = c;
        data[0][2] = l;
        len = 0;
    }

    void insert(int r, int c, int v);
    void disp();
    Sparse_mat transpose();
    Sparse_mat fastTranspose();
    Sparse_mat add(Sparse_mat b);
    Sparse_mat multiply(Sparse_mat b);
};

void Sparse_mat::insert(int r, int c, int v)
{
    if (r >= data[0][0] || c >= data[0][1] || len >= max)
    {
        cout << "Invalid data or matrix is full" << endl;
    }
    else
    {
        data[len + 1][0] = r;
        data[len + 1][1] = c;
        data[len + 1][2] = v;
        len++;
    }
}

void Sparse_mat::disp()
{
    cout << "\nRow\tColumn\tValue" << endl;
    for (int i = 0; i <= len; i++)
    {
        cout << data[i][0] << "\t" << data[i][1] << "\t" << data[i][2] << endl;
    }
}

Sparse_mat Sparse_mat::transpose()
{
    Sparse_mat t(data[0][1], data[0][0], data[0][2]);
    t.len = 0;

    for (int i = 0; i < data[0][1]; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            if (data[j][1] == i)
            {
                t.len++;
                t.data[t.len][0] = data[j][1];
                t.data[t.len][1] = data[j][0];
                t.data[t.len][2] = data[j][2];
            }
        }
    }
    return t;
}

Sparse_mat Sparse_mat::fastTranspose()
{
    Sparse_mat t(data[0][1], data[0][0], data[0][2]);
    int rowTerms[max] = {0}, startPos[max] = {0};

    for (int i = 1; i <= len; i++)
    {
        rowTerms[data[i][1]]++;
    }

    startPos[0] = 1;
    for (int i = 1; i < data[0][1]; i++)
    {
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 1; i <= len; i++)
    {
        int pos = startPos[data[i][1]];
        t.data[pos][0] = data[i][1];
        t.data[pos][1] = data[i][0];
        t.data[pos][2] = data[i][2];
        startPos[data[i][1]]++;
    }
    t.len = len;
    return t;
}

Sparse_mat Sparse_mat::add(Sparse_mat b)
{
    if (data[0][0] != b.data[0][0] || data[0][1] != b.data[0][1])
    {
        cout << "Matrices cannot be added due to dimension mismatch!" << endl;
        return Sparse_mat(0, 0, 0);
    }

    Sparse_mat result(data[0][0], data[0][1], 0);
    int apos = 1, bpos = 1;

    while (apos <= len && bpos <= b.len)
    {
        if (data[apos][0] == b.data[bpos][0] && data[apos][1] == b.data[bpos][1])
        {
            int added_value = data[apos][2] + b.data[bpos][2];
            if (added_value != 0)
            {
                result.insert(data[apos][0], data[apos][1], added_value);
            }
            apos++;
            bpos++;
        }
        else if (data[apos][0] < b.data[bpos][0] ||
                 (data[apos][0] == b.data[bpos][0] && data[apos][1] < b.data[bpos][1]))
        {
            result.insert(data[apos][0], data[apos][1], data[apos][2]);
            apos++;
        }
        else
        {
            result.insert(b.data[bpos][0], b.data[bpos][1], b.data[bpos][2]);
            bpos++;
        }
    }

    while (apos <= len)
    {
        result.insert(data[apos][0], data[apos][1], data[apos][2]);
        apos++;
    }

    while (bpos <= b.len)
    {
        result.insert(b.data[bpos][0], b.data[bpos][1], b.data[bpos][2]);
        bpos++;
    }

    return result;
}

Sparse_mat Sparse_mat::multiply(Sparse_mat b)
{
    if (data[0][1] != b.data[0][0])
    {
        cout << "Matrices cannot be multiplied due to dimension mismatch!" << endl;
        return Sparse_mat(0, 0, 0);
    }

    Sparse_mat result(data[0][0], b.data[0][1], 0);

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= b.len; j++)
        {
            if (data[i][1] == b.data[j][0])
            {
                int r = data[i][0];
                int c = b.data[j][1];
                int val = data[i][2] * b.data[j][2];
                int pos;

                for (pos = 1; pos <= result.len; pos++)
                {
                    if (result.data[pos][0] == r && result.data[pos][1] == c)
                    {
                        result.data[pos][2] += val;
                        break;
                    }
                }

                if (pos > result.len)
                {
                    result.insert(r, c, val);
                }
            }
        }
    }

    return result;
}

int main()
{
    int choice, r1, c1, l1, r2, c2, l2;

    cout << "Enter number of rows for matrix A: ";
    cin >> r1;
    cout << "Enter number of columns for matrix A: ";
    cin >> c1;
    cout << "Enter number of non-zero elements in matrix A: ";
    cin >> l1;
    Sparse_mat A(r1, c1, l1);

    for (int i = 0; i < l1; i++)
    {
        int r, c, val;
        cout << "Enter row number: ";
        cin >> r;
        cout << "Enter column number: ";
        cin >> c;
        cout << "Enter non-zero value: ";
        cin >> val;
        A.insert(r, c, val);
    }

    cout << "Enter number of rows for matrix B: ";
    cin >> r2;
    cout << "Enter number of columns for matrix B: ";
    cin >> c2;
    cout << "Enter number of non-zero elements in matrix B: ";
    cin >> l2;
    Sparse_mat B(r2, c2, l2);

    for (int i = 0; i < l2; i++)
    {
        int r, c, val;
        cout << "Enter row number: ";
        cin >> r;
        cout << "Enter column number: ";
        cin >> c;
        cout << "Enter non-zero value: ";
        cin >> val;
        B.insert(r, c, val);
    }

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Display Matrix A\n";
        cout << "2. Display Matrix B\n";
        cout << "3. Transpose Matrix A\n";
        cout << "4. Fast Transpose Matrix A\n";
        cout << "5. Add Matrices A and B\n";
        cout << "6. Multiply Matrices A and B\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Matrix A:";
            A.disp();
            break;
        case 2:
            cout << "Matrix B:";
            B.disp();
            break;
        case 3:
            cout << "Transpose of Matrix A:";
            A.transpose().disp();
            break;
        case 4:
            cout << "Fast Transpose of Matrix A:";
            A.fastTranspose().disp();
            break;
        case 5:
            cout << "Addition of Matrices A and B:";
            A.add(B).disp();
            break;
        case 6:
            cout << "Multiplication of Matrices A and B:";
            A.multiply(B).disp();
            break;
        case 7:
            cout << "Exiting.";
            break;
        default:
            cout << "Invalid choice.";
            break;
        }
    } while (choice != 7);

    return 0;
}

/*
omkar = 100
digvijay = 30
yogesh = 25
optional - abhay = 25
optional - sujal = 25
*/