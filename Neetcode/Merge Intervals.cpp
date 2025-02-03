class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size(), k=0;
        vector<vector<int>> ans(1, intervals[0]);

        // ans.back() can be used instead of k
        for(int i=1; i<n ; ++i) {
            if(ans[k][1] < intervals[i][0]) {
                ++k;
                ans.push_back(intervals[i]);
            }
            else {
                ans[k][1] = max(ans[k][1], intervals[i][1]);
            }
        }

        return ans;
    }
};
