class Solution {
public:
    string shortestPalindrome(string &s) {
        string revs = s;
        reverse(revs.begin(), revs.end());
        string s1 = s + "#" + revs;
        const int n1 = s1.size();
        vector<int> lps(n1, 0);
        lps[0] = 0;
        for (int x = 0, y = 1; y < n1; ++y) {
            if (s1[x] == s1[y]) {
                lps[y] = x + 1;
                ++x;
            } else {
                x = lps[x == 0 ? 0 : x - 1];
                if (s1[x] == s1[y])
                    lps[y] = x++ + 1;
                else {
                    lps[y] = 0;
                    x = 0;
                }
            }
        }

        string toAdd = s.substr(lps[n1 - 1]);
        reverse(toAdd.begin(), toAdd.end());
        return toAdd + s;
    }
};
