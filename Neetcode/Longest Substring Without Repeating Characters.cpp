class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), max_len = 0;
        unordered_set<char> uc; //stores unique characters
        while(r<n) {
            while(uc.count(s[r]) && l<r) {
                uc.erase(s[l++]);
            }
            max_len = max(max_len, r-l+1);
            uc.insert(s[r++]);
        }
        return max_len;
    }
};
