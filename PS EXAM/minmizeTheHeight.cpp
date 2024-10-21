//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 0) return 0; // If the array is empty, return 0
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        
        // Step 2: Initialize potential new max and min
        int minHeight = arr[0] + k; // Minimum height after adding k to the smallest
        int maxHeight = arr[n-1] - k; // Maximum height after subtracting k from the largest

        // If the new maximum is less than the new minimum, return the difference is zero
        // if (minHeight > maxHeight) {
        //     return minHeight + maxHeight;
        // }
        
        // Step 3: Return the difference
        return maxHeight - minHeight;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends