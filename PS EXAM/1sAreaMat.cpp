//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> height(m, 0);
        int max_area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
            if (M[i][j] == 0) {
                height[j] = 0;
            } else {
                height[j] += 1;
            }
            }

            stack<int> s;
            int area = 0;
            int k = 0;
            while (k < m) {
            if (s.empty() || height[s.top()] <= height[k]) {
                s.push(k++);
            } else {
                int tp = s.top();
                s.pop();
                area = height[tp] * (s.empty() ? k : k - s.top() - 1);
                max_area = max(max_area, area);
            }
            }

            while (!s.empty()) {
            int tp = s.top();
            s.pop();
            area = height[tp] * (s.empty() ? k : k - s.top() - 1);
            max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends