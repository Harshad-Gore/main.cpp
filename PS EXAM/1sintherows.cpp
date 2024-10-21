//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int max1sRow = -1;
        int max1sCount = 0;
        int n = arr.size();
        int m = arr[0].size();
        
        for (int i = 0; i < n; i++) {
            int count1s = count(arr[i].begin(), arr[i].end(), 1);
            if (count1s > max1sCount) {
            max1sCount = count1s;
            max1sRow = i;
            }
        }
        
        return max1sRow;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends