class Solution {
public:
    int minExtraChar(string& s, vector<string>& dictionary) {
        int n = s.size(), minChars;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i, minChars = INT_MAX) {
            for (auto it : dictionary)
                if (it.size() <= i && s.substr(i - it.size(), it.size()) == it)
                    minChars = min(minChars, dp[i - it.size()]);

            dp[i] = min(dp[i - 1] + 1, minChars);
        }
        return dp[n];
    }
};
