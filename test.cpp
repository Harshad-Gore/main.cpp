#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSetBits(int n)
    {
        int count_total = 0;
        for (int i = 1; i <= n; i++)
        {
            int count = 0;
            int num = i;
            while (num)
            {
                num = num & (num - 1);
                count++;
            }
            count_total += count;
        }
        return count_total;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        int cnt = ob.countSetBits(n);
        cout << cnt << endl;
    }
    return 0;
}