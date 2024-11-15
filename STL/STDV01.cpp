// c++ Program to initializ the std::vector with specific value
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v(5, 11);

    for (auto i : v)
        cout << i << " ";
    return 0;
}
