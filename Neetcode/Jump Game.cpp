class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        if(nums[0] == 0) return false;

        int n = nums.size(), first_non_reachable_step = 1;
        for(int i=0;i<n-1;++i) {
            if(nums[i] && i<first_non_reachable_step) {
                first_non_reachable_step = max(first_non_reachable_step, i+nums[i]+1);
            }
        }
        return n-1 < first_non_reachable_step;
    }
};
