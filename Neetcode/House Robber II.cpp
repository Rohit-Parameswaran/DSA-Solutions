class Solution {
public:
    int robHouses(vector<int> nums) {
        int first = 0, second = nums[0], t;
        for(int i=1; i<nums.size() ; ++i) {
            t = second;
            second = max(first + nums[i], second);
            first = t;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int rob_first =  robHouses(vector<int> (nums.begin(), nums.end()-1));
        int n_rob_first = robHouses(vector<int> (nums.begin()+1, nums.end()));
        return max(rob_first, n_rob_first);
    }
};
