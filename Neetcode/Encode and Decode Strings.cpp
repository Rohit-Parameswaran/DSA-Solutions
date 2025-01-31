class Solution {
public:

    string encode(vector<string>& strs) {
        string ans("");
        for(auto str: strs) {
            ans += to_string(str.size()) + "#" + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size(), l=0, cur_num=0;
        string cur_str;
        for(int i=0 ; i<n ; ++i) {
            if(s[i] != '#'){
                cur_num = cur_num*10 + (s[i]-'0');
            }
            else {
                cur_str = s.substr(i+1, cur_num);
                ans.push_back(cur_str);
                i += cur_num;
                cur_str = "";
                cur_num = 0;
            }
        }
        return ans;
    }
};
