class Solution {
    unordered_map<char, char> matching;
public:
    Solution() {
        matching[')'] = '(';
        matching['}'] = '{';
        matching[']'] = '[';
    }

    bool isValid(string str) {
        stack<char> s;
        for(auto it: str) {
            if(it == '(' || it =='{' || it == '[') s.push(it);
            else if (s.empty() || matching[it] != s.top()) return false;
            else s.pop();
        }
        return s.empty();
    }
};
