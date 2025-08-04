class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_freq;
        unordered_map<char, int> s_freq;
        int t_dist = 0, s_matched = 0, n = s.size(), minStart = -1, minEnd = -1, minLength = INT_MAX, curStart = 0;

        for(auto it: t) {
            ++t_freq[it];
            if(t_freq[it] == 1) t_dist++;
        }

        for(int i=0 ; i<n ; ++i) {
            char curLetter = s[i];
            ++s_freq[curLetter];
            if(s_freq[curLetter] == t_freq[curLetter]) {
                ++s_matched;
            }

            while(curStart <=i && t_dist == s_matched) {
                if(i-curStart+1 < minLength) {
                    minStart = curStart, minEnd = i;
                    minLength = minEnd-minStart+1;
                }
                if(t_freq.count(s[curStart]) != 0 && s_freq[s[curStart]]-1 < t_freq[s[curStart]]) {
                    --s_matched;
                }
                --s_freq[s[curStart]];
                ++curStart;
            }
        }

        return (minStart == -1) ? "" : s.substr(minStart, minLength);
    }
};
