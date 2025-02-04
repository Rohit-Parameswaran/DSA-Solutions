class Solution {
public:
    string getPalindromeWithMid(string &s, int l, int r) {
        string res;
        while(l>=0 && r<s.size() && s[l] == s[r]) {
            res = l == r ? s[l] + res : s[l] + res + s[r];
            --l, ++r;
        }
        return res;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string max_str;
        max_str.push_back(s[0]);
        for(int i=1 ; i<n ; ++i) {
            string op = getPalindromeWithMid(s, i, i);
            string ep = getPalindromeWithMid(s, i-1, i);
            if(max_str.size() < op.size()) max_str = op;
            if(max_str.size() < ep.size()) max_str = ep;
        }
        return max_str;
    }
};
