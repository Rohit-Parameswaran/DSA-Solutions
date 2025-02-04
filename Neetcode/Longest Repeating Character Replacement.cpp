class Solution {
public:
    int getMajorityCharacter(unordered_map<char, int> &fc) {
        int maxFreq = 0;
        for(auto it: fc)
            if(it.second > maxFreq)
                maxFreq = it.second;
        return maxFreq;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> fc;
        ++fc[s[0]];
        int max_len=1, l=0, r=1, n=s.size(), max_freq=1;
        while(r < n) {
            ++fc[s[r]];
            // if current character freq is greater than majority character freq
            // reassign maj_ch
            max_freq = max(max_freq, fc[s[r]]);
            
            while(l<r && (r-l+1)-max_freq > k) {
                --fc[s[l]];
                ++l;
                max_freq = getMajorityCharacter(fc);
            }
            max_len = max(max_len, r-l+1);
            ++r;
        }
        return max_len;
    }
};
