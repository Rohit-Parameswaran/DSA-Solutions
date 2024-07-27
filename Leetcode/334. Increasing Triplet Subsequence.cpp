class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_left(n), max_right(n);
        int curMin = nums[0], curMax = nums[n - 1];
        for (int i = 0, j = n - 1; i < n && j >= 0; ++i, --j) {
            min_left[i] = curMin;
            curMin = min(curMin, nums[i]);

            max_right[j] = curMax;
            curMax = max(curMax, nums[j]);
        }

        for (int i = 1; i < n - 1; ++i) {
            if (min_left[i] < nums[i] && nums[i] < max_right[i])
                return true;
        }
        return false;
    }
};
