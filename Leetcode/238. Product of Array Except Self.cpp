class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), curPostProd = 1;
        vector<int> pre(n), post(n);
        pre[0] = 1;
        for(int i=1; i<n; ++i)
            pre[i] = nums[i-1] * pre[i-1];

        for(int i=n-1; i>=0 ; --i) {
            post[i] = pre[i] * curPostProd;
            curPostProd *= nums[i];
        }
        return post;
    }
};
