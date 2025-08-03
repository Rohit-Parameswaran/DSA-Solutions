class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen;
        vector<int> dp(n, 1);
        for(int i=0 ; i<n ; ++i) {
            maxLen = 1;
            for(int j=0 ; j<i ; ++j)
                if(nums[i] > nums[j])
                    maxLen = max(maxLen, dp[j]+1);
            dp[i] = maxLen;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
