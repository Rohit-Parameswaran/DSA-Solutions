class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target, int l=0) {
        if(target == 0) return {{}};
        else if(l >= nums.size() || target < 0) return {};

        vector<vector<int>> result, temp;
        for(int i=l; i<nums.size() ; ++i) {
            temp = combinationSum(nums, target-nums[i], i);
            if(temp.size() != 0) {
                for(vector<int> &combination: temp)
                    combination.push_back(nums[i]);
            }
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};
