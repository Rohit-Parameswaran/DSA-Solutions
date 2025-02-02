class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), m = wordDict.size();
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;

        for(int i=1 ; i<=n ; ++i) {
            for(auto word: wordDict) {
                int wordSize = word.size();
                if(s[i-1] == word[wordSize-1] && i-wordSize >= 0) // if current string character is same as last letter of a valid word
                    {
                        string str_to_consider = s.substr(i-wordSize, wordSize);
                        if(str_to_consider == word)
                            dp[i] = dp[i] || dp[i-wordSize];
                    }
            }
        }

        return dp[n];
    }
};
