class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), curCount = 1, totalLength = 0;
        char curChar;
        for (int i = 1; i < n; ++i) {
            if (chars[i] != chars[i - 1]) {
                curChar = chars[i - 1];
                chars[totalLength++] = curChar;
                if (curCount > 1) {
                    string countStr = to_string(curCount);
                    for (auto it : countStr)
                        chars[totalLength++] = it;
                }
                curCount = 1;
            } else {
                ++curCount;
            }
        }
        chars[totalLength++] = chars[n - 1];
        if (curCount > 1) {
            string countStr = to_string(curCount);
            for (auto it : countStr)
                chars[totalLength++] = it;
        }
        return totalLength;
    }
};
