class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0, n=nums.size();
        double curSum = 0, maxAvg = INT_MIN;
        while(i<k) curSum += nums[i++];
        maxAvg = curSum/k;

        while(i<n) {
            curSum += nums[i] - nums[i-k];
            if(maxAvg < curSum/k) maxAvg = curSum/k;
            ++i;
        }

        return maxAvg;
    }
};
