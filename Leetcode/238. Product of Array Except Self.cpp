class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        vector<int> post(n, 1);
        for(int i=1, j=n-2; i<n && j>=0 ; ++i, --j) {
            pre[i] = nums[i-1] * pre[i-1];
            post[j] = nums[j+1] * post[j+1];
        }
        vector<int> result(n);
        for(int i=0;i<n;++i)
            result[i] = pre[i] * post[i];
        return result;
    }
};
