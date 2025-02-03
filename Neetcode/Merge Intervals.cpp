class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (vector<int> a, vector<int> b) {
            if(a[0] == b[0])
                return a[1]<b[1];
            return a[0] < b[0];
        });

        int n = intervals.size(), l=intervals[0][0], r=intervals[0][1], k=0;
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

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
