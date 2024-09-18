class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comparator = [] (int& a, int& b) {
            auto x = to_string(a), y = to_string(b);
            return x + y > y + x;
        };
        sort(nums.begin(), nums.end(), comparator);
        string ans = "";
        for (auto it : nums)
            ans += to_string(it);
        return ans[0] == '0' ? "0" : ans;
    }
};
