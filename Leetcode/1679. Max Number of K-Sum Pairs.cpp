class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size(), ans=0;
        unordered_map<int, int> count;
        for(auto it: nums) count[it]++;
        for(int i=0;i<n;++i) {
            if(k-nums[i] != nums[i] && count[nums[i]] > 0 && count[k-nums[i]] > 0) {
                ++ans;
                --count[nums[i]];
                --count[k-nums[i]];
            }

            else if(k-nums[i] == nums[i] && count[nums[i]] >= 2) {
                ++ans;
                count[nums[i]] -= 2;
            }
        }

        return ans;
    }
};
