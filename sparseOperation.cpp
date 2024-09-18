#include <iostream>
#define MAX 50
using namespace std;

class sparse
{
    int sp[MAX][3];
    int len;

public:
    sparse() {}

    sparse(int r, int c, int v)
    {
        sp[0][0] = r;
        sp[0][1] = c;
        sp[0][2] = v;
        len = 0;
    }

    void insert(int row, int col, int val);

    void display();

    sparse transpose();

    void add(sparse s2);

    void fast_tr(sparse s1);

    void editMat(sparse s1);

    void multi(sparse s1, sparse s2);
};

void sparse ::insert(int row, int col, int val)
{
    if (row >= sp[0][0] || col >= sp[0][1])
    {
        cout << "Invalid row or column number" << endl;
    }
    else
    {
        sp[len + 1][0] = row;
        sp[len + 1][1] = col;
        sp[len + 1][2] = val;
        len++;
    }
}

void sparse ::display()
{
    cout << "row\tcol\tval" << endl;
    for (int i = 0; i <= len; i++)
    {
        cout << sp[i][0] << "\t" << sp[i][1] << "\t" << sp[i][2] << endl;
    }
}

sparse sparse::transpose()
{
    sparse t(sp[0][1], sp[0][0], sp[0][2]);
    for (int i = 0; i < sp[0][1]; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            if (sp[j][1] == i)
            {
                t.len++;
                t.sp[t.len][0] = sp[j][1];
                t.sp[t.len][1] = sp[j][0];
                t.sp[t.len][2] = sp[j][2];
            }
        }
    }
    return t;
}

void sparse::add(sparse s2)
{
    if (sp[0][0] != s2.sp[0][0] || sp[0][1] != s2.sp[0][1])
    {
        cout << "Cannot add matrices of different dimensions." << endl;
        return;
    }

    sparse result(sp[0][0], sp[0][1], 0);
    int s1pos = 1, s2pos = 1;

    while (s1pos <= len && s2pos <= s2.len)
    {
        if ((sp[s1pos][0] < s2.sp[s2pos][0]) || (sp[s1pos][0] == s2.sp[s2pos][0] && sp[s1pos][1] < s2.sp[s2pos][1]))
        {
            result.len++;
            result.sp[result.len][0] = sp[s1pos][0];
            result.sp[result.len][1] = sp[s1pos][1];
            result.sp[result.len][2] = sp[s1pos][2];
            s1pos++;
        }
        else if ((sp[s1pos][0] > s2.sp[s2pos][0]) || (sp[s1pos][0] == s2.sp[s2pos][0] && sp[s1pos][1] > s2.sp[s2pos][1]))
        {
            result.len++;
            result.sp[result.len][0] = s2.sp[s2pos][0];
            result.sp[result.len][1] = s2.sp[s2pos][1];
            result.sp[result.len][2] = s2.sp[s2pos][2];
            s2pos++;
        }
        else
        {
            result.len++;
            result.sp[result.len][0] = sp[s1pos][0];
            result.sp[result.len][1] = sp[s1pos][1];
            result.sp[result.len][2] = sp[s1pos][2] + s2.sp[s2pos][2];
            s1pos++;
            s2pos++;
        }
    }

    while (s1pos <= len)
    {
        result.len++;
        result.sp[result.len][0] = sp[s1pos][0];
        result.sp[result.len][1] = sp[s1pos][1];
        result.sp[result.len][2] = sp[s1pos][2];
        s1pos++;
    }
    while (s2pos <= s2.len)
    {
        result.len++;
        result.sp[result.len][0] = s2.sp[s2pos][0];
        result.sp[result.len][1] = s2.sp[s2pos][1];
        result.sp[result.len][2] = s2.sp[s2pos][2];
        s2pos++;
    }

    result.sp[0][2] = result.len;
    result.display();
}

void sparse::fast_tr(sparse s1)
{
    int i, colno, x;
    int *cnt = new int[s1.sp[0][1]]();
    int *loc = new int[s1.sp[0][1]];

    for (i = 1; i <= s1.len; i++)
    {
        colno = s1.sp[i][1];
        cnt[colno]++;
    }
    loc[0] = 1;
    for (i = 1; i < s1.sp[0][1]; i++)
    {
        loc[i] = loc[i - 1] + cnt[i - 1];
    }
    for (i = 1; i <= s1.len; i++)
    {
        colno = s1.sp[i][1];
        x = loc[colno]++;
        sp[x][0] = s1.sp[i][1];
        sp[x][1] = s1.sp[i][0];
        sp[x][2] = s1.sp[i][2];
    }
}
void sparse::editMat(sparse s1)
{
    for (int i = 0; i < s1.sp[0][1]; i++)
    {
        sp[0][0] = s1.sp[i][0];
        sp[0][1] = s1.sp[i][1];
        sp[0][2] = s1.sp[i][2];
    }
}
void sparse::multi(sparse s1, sparse s2)
{
    if (s1.sp[0][1] != s2.sp[0][0])
    {
        cout << "Cannot Multiply" << endl;
        return;
    }
    sparse s4 = s2.transpose();
    sparse result(s1.sp[0][0], s2.sp[0][1], 0);

    int i = 1, k = 1;
    while (i <= s1.len)
    {
        int row = s1.sp[i][0];
        for (int j = 1; j <= s4.len;)
        {
            int col = s4.sp[j][0];
            int sum = 0;
            int a = i, b = j;

            while (a <= s1.len && b <= s4.len && s1.sp[a][0] == row && s4.sp[b][0] == col)
            {
                if (s1.sp[a][1] == s4.sp[b][1])
                {
                    sum += s1.sp[a][2] * s4.sp[b][2];
                    a++;
                    b++;
                }
                else if (s1.sp[a][1] < s4.sp[b][1])
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }
            if (sum != 0)
            {
                result.sp[k][0] = row;
                result.sp[k][1] = col;
                result.sp[k][2] = sum;
                k++;
            }

            while (j <= s4.len && s4.sp[j][0] == col)
                j++;
        }
        while (i <= s1.len && s1.sp[i][0] == row)
            i++;
    }

    result.sp[0][2] = k - 1;
    result.len = k - 1;

    result.display();
}

int main()
{
    int r1, c1, v1;
    int r, c, v;

    cout << "Enter the number of rows of 1st sparse matrix: ";
    cin >> r1;
    cout << "Enter the number of columns of 1st sparse matrix: ";
    cin >> c1;
    cout << "Enter the number of non-zero values of 1st sparse matrix: ";
    cin >> v1;

    sparse s1(r1, c1, v1);

    for (int i = 0; i < v1; i++)
    {
        cout << "Enter row number: ";
        cin >> r;
        cout << "Enter column number: ";
        cin >> c;
        cout << "Enter value: ";
        cin >> v;
        s1.insert(r, c, v);
    }

    cout << "The 1st sparse matrix is: " << endl;
    s1.display();

    int r2, c2, v2;
    cout << "Enter the number of rows of 2nd sparse matrix: ";
    cin >> r2;
    cout << "Enter the number of columns of 2nd sparse matrix: ";
    cin >> c2;
    cout << "Enter the number of non-zero values of 2nd sparse matrix: ";
    cin >> v2;

    sparse s2(r2, c2, v2);

    for (int i = 0; i < v2; i++)
    {
        cout << "Enter row number: ";
        cin >> r;
        cout << "Enter column number: ";
        cin >> c;
        cout << "Enter value: ";
        cin >> v;
        s2.insert(r, c, v);
    }

    cout << "The 2nd sparse matrix is: " << endl;
    s2.display();

    int option;
    cout << "Enter 1 to Add matrices, 2 to Multiply matrices, 3  transpose , 4 Fast transpose";
    cin >> option;

    switch (option)
    {
    case 1:
        s1.add(s2);
        break;

    case 2:
        s1.multi(s1, s2);
        break;

    case 3:
        s1.transpose();
        break;

    case 4:
        s1.fast_tr(s1);
        break;

    case 5:
        cout << "exit" << endl;
        break;
    default:
        cout << "Invalid Option" << endl;
        break;
    }

    return 0;
    while (option != 5);
}
