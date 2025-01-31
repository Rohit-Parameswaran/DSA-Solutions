class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=0, r=0, n=nums.size(), max_sum=INT_MIN, cur_sum = 0;
        while(r<n) {
            cur_sum += nums[r];
            if(nums[r] >= cur_sum) {
                l=r;
                cur_sum = nums[r];
            }
            max_sum = max(cur_sum, max_sum);
            ++r;
        }
        return max_sum;
    }
};
