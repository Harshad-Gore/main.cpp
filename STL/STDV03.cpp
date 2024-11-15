// C++ Program to initializ the std::vector
// using std::iota()
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);

    iota(v.begin(), v.end(), 11);

    for (auto i : v)
        cout << i << " ";
    return 0;
}
