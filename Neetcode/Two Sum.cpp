class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vimap;
        int n = nums.size();
        
        for(int i=0 ; i<n ; ++i) {
            if(vimap[target - nums[i]]) {
                return {vimap[target - nums[i]]-1, i};
            }
            vimap[nums[i]] = i+1;
        }
        return {-1, -1};
    }
};
