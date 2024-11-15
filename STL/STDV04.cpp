// C++ Program to initialize the std::vector
// using std::fill() method
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);

    fill(v.begin(), v.end(), 11);

    for (auto i : v)
        cout << i << " ";
    return 0;
}
