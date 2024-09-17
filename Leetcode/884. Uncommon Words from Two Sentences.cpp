class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string &s2) {
        stringstream ss(s1 + " " + s2);
        unordered_map<string, int> m;
        vector<string> ans;

        while (ss >> s1)
            ++m[s1];

        for (auto it : m) {
            if (it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};
