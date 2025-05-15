class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (auto &a, auto&b) {
            return a[0] < b[0];
        });

        int ans=0, n=intervals.size(), prevEnd=intervals[0][1];
        for(int i=1; i<n ; ++i) {
            if(intervals[i][0] >= prevEnd)
                prevEnd = intervals[i][1];
            else {
                prevEnd = min(intervals[i][1], prevEnd);
                ++ans;
            }
        }
        return ans;
    }
};
