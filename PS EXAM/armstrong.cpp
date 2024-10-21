//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int original = n;
        int sum = 0;
        int x = 0;
        while (n != 0)
        {
            n = n/10;
            x++;
        }
        n = original;
        while (n != 0)
        {
            int digit = n % 10;
            sum += pow(digit,x);
            n = n/10;
        }
        if (sum == original)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

