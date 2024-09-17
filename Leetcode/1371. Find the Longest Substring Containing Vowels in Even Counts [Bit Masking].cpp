class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> sc(32, -2);
        int a = 16, e = 8, i = 4, o = 2, u = 1, cc = 0, maxLength = 0;
        sc[0] = -1;

        for (int x = 0; x < s.size(); ++x) {
            switch (s[x]) {
            case 'a':
                cc ^= a;
                break;
            case 'e':
                cc ^= e;
                break;
            case 'i':
                cc ^= i;
                break;
            case 'o':
                cc ^= o;
                break;
            case 'u':
                cc ^= u;
                break;
            default:
                break;
            }
            if (sc[cc] != -2)
                maxLength = max(maxLength, x - sc[cc]);
            else
                sc[cc] = x;
        }
        return maxLength;
    }
};

// another amazing solution in submissions
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/solutions/531840/java-c-python-one-pass/

int findTheLongestSubstring(string s) {
    unordered_map<int, int> m{{0, -1}};
    int res = 0, n = s.length(), cur = 0;
    for (int i = 0; i < n; i++) {
        cur ^= 1 << string("aeiou").find(s[i]) + 1 >> 1;
        if (!m.count(cur)) m[cur] = i;
        res = max(res, i - m[cur]);
    }
    return res;
}
