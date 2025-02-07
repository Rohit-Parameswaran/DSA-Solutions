class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if(s[0] == '0') return 0;
        int a = 1, b = 1, c = 0;
        
        for(int i=1; i<n; ++i) {
            if(s[i] == '0' && s[i-1] != '1' && s[i-1] != '2') return 0;
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
                c += a;
            c += s[i] == '0' ? 0 : b;
            a = b, b = c, c = 0;
        }
        return b;
    }
};
