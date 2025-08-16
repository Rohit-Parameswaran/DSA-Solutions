class Solution {
public:
    int jump(vector<int>& nums) {
        int curFarthest = 0, nextFarthest = 0, jumps = 0, n = nums.size();
        for (int i = 0; i<n && curFarthest < n-1; ++i) {
            nextFarthest = max(nextFarthest, i + nums[i]);
            if (i == curFarthest) {
                ++jumps;
                curFarthest = nextFarthest;
            }
        }
        return jumps;
    }
};
