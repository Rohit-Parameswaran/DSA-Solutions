class Solution {
  public:
    int longestSubarray(vector<int>& nums, int k) {
        long long curSum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        int n=nums.size(), maxLength=0;
        for(int i=0 ; i<n ; ++i) {
            curSum += nums[i];
            if(prefixSum.count(curSum) == 0)
                prefixSum[curSum] = i;
            if(prefixSum.count(curSum-k)) {
                maxLength = max(maxLength, i-prefixSum[curSum-k]);
            }
        }
        return maxLength;
    }
};
