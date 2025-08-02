class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1,m=l+(r-l)/2;
        while(l!=r) {
            if(nums[m] < nums[r]) r = m;
            else l=m+1;
            m = l+(r-l)/2;
        }
        return nums[m];
    }
};
