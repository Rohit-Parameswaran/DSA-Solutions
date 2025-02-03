class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int curMax = 0, i;

        for(auto it: nums) {
            if(numSet.count(it-1) == 0) {
                i = it;
                while(numSet.count(i)) 
                    ++i;
                curMax = max(i-it, curMax);
            }
        }

        return curMax;
    }
};
