class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> lprod(n,1);
        vector<int> rprod(n,1);
        vector<int> ans;

        for(int i=1, j=n-2 ; i<n && j>=0 ; ++i, --j) {
            lprod[i] = lprod[i-1] * nums[i-1];
            rprod[j] = rprod[j+1] * nums[j+1]; 
        }

        for(int i=0; i<n ; ++i) {
            ans.push_back(lprod[i]*rprod[i]);
        }

        return ans;
    }
};
