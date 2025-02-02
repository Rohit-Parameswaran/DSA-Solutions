class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size(), i=0;
        while(i<n) {
            int l=i+1, r = n-1;
            while(l<r) {
                if(nums[l] + nums[r] == -nums[i]) {
                    ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while(++l<r && nums[l] == nums[l-1]);
                }
                else if (nums[l] + nums[r] < -nums[i]) ++l;
                else --r;
            }
            while(++i<n && nums[i] == nums[i-1]);
        }
        return ans;
    }
};
