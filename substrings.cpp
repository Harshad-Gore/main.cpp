#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxUniqueSplit(string s) {
        int len = s.size();
        unordered_set<string> seen;
        function<int(int)> dfs = [&](int start) {
            if (start == len) return 0;
            int maxSplit = 0;
            for (int end = start + 1; end <= len; ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxSplit = max(maxSplit, 1 + dfs(end));
                seen.erase(substring);
            }
            }
            return maxSplit;
        };
        return dfs(0);
    }
};
int main()
{
    Solution s;
    cout << s.maxUniqueSplit("ababccc") << endl;
    return 0;
}