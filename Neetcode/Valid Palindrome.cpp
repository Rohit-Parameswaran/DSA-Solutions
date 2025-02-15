class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size(), l=0, r=n-1;
        while(l<r) {
            while(l<r && !isalnum(s[l])) ++l; 
            while(l<r && !isalnum(s[r])) --r;
            if(toupper(s[l]) != toupper(s[r])) return false;
            ++l, --r;
        }
        return true;
    }
};
