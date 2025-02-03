class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(auto word: strs) {
            vector<int> fc(26, 0);
            for(auto ch: word) ++fc[ch-'a'];
            string keystr;
            for(auto it: fc)
                keystr += "@" + to_string(it);
            m[keystr].push_back(word);
        }

        vector<vector<string>> ans;
        for(auto it: m) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
