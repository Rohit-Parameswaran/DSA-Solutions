class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1, m;
        while(l<=r) {
            m = l+(r-l)/2;
            if(nums[m] == target) return m;
            else if(nums[l] <= nums[m]) {
                if(nums[l] <= target && target < nums[m]) r = m-1;
                else l = m+1;
            }
            else {
                if(nums[r] >= target && target > nums[m]) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};
