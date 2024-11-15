// C++ Program to initializ the std::vector
// from another vector
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1 = {11, 23, 45, 89};

    vector<int> v2(v1.begin(), v1.end());

    for (auto i : v2)
        cout << i << " ";
    return 0;
}
