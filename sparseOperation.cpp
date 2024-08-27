#include <iostream>
#define MAX 50
using namespace std;

class sparse
{
    int sp[MAX][3];
    int len;

public:
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
//Edit elements of sparse matrix
void sparse::editMat(sparse s1){
    for (int i = 0; i < s1.sp[0][1];i++){
        sp[0][0]=s1.sp[i][0];
        sp[0][1]=s1.sp[i][1];
        sp[0][2]=s1.sp[i][2];
    }
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
        cout << "Enter the value: ";
        cin >> v;
        s1.insert(r, c, v);
    }

    s1.display();

    cout << "Enter the number of rows of 2nd sparse matrix: ";
    cin >> r1;
    cout << "Enter the number of columns of 2nd sparse matrix: ";
    cin >> c1;
    cout << "Enter the number of non-zero values of 2nd sparse matrix: ";
    cin >> v1;

    sparse s2(r1, c1, v1);

    for (int i = 0; i < v1; i++)
    {
        cout << "Enter row number: ";
        cin >> r;
        cout << "Enter column number: ";
        cin >> c;
        cout << "Enter the value: ";
        cin >> v;
        s2.insert(r, c, v);
    }

    s2.display();

    s1.add(s2);

    return 0;
}
