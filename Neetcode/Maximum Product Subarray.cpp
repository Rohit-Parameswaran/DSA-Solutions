class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], curMinProd = nums[0], n=nums.size(), curMaxProd = nums[0], prevProd=1;
        for(auto num: nums) {
            prevProd = curMaxProd;
            curMaxProd = max({num, prevProd * num, curMinProd * num});
            curMinProd = min({num, prevProd * num, curMinProd * num});
            maxProd = max(maxProd, curMaxProd);
        }
        return maxProd;
    }
};
