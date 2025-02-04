class Solution {
public:
    int getPalindromesWithMid(string &s, int l, int r) {
        int n=s.size(), res = 0;
        while(l>=0 && r<n && s[l] == s[r]) {
           ++res;
           --l, ++r;
        }
        return res;
    }

    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for(int i=0; i<n ; ++i)
            res += getPalindromesWithMid(s, i, i) + getPalindromesWithMid(s, i-1, i);
        return res;
    }
};
