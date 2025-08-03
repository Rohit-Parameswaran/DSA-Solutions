// O(n²)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen;
        vector<int> dp(n, 1);
        for(int i=0 ; i<n ; ++i) {
            maxLen = 1;
            for(int j=0 ; j<i ; ++j)
                if(nums[i] > nums[j])
                    maxLen = max(maxLen, dp[j]+1);
            dp[i] = maxLen;
        }
        return *max_element(dp.begin(), dp.end());
    }
};


// O(nlogn)
class Solution {
public:
    void insertIntoPile(vector<int> &tails, const int &num) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if(it == tails.end()) tails.push_back(num);
        else *it = num;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(auto num: nums)
            insertIntoPile(tails, num);
        return tails.size();
    }
};

// O(nlogn) -> My solution with manual binary search
class Solution {
public:
    void insertIntoPile(vector<int> &tails, const int &num) {
        int n=tails.size();
        if(n == 0) tails.push_back(num);

        int l=0, r=n-1, m;
        while(l<r) {
            m = l+(r-l)/2;
            if(tails[m] >= num) r=m;
            else l=m+1;
        }
        if(num > tails[l]) tails.push_back(num);
        else tails[l] = min(tails[l], num);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(auto num: nums)
            insertIntoPile(tails, num);
        return tails.size();
    }
};
