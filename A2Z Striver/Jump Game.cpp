class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0, n = nums.size();
        for(int i=0 ; i<n && maxReachable < n-1 ; ++i) {
            if(i <= maxReachable) {
                maxReachable = max(maxReachable, i+nums[i]); 
            }
            else break;
        }
        return n-1 <= maxReachable;
    }
};
