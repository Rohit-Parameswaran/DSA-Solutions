class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> compInterval = newInterval;
        vector<vector<int>> result;
        int n = intervals.size(), i=0;

        while(i<n && intervals[i][1] < compInterval[0]) {
            result.push_back(intervals[i]);
            ++i;
        }
    
        while(i<n && intervals[i][0] <= compInterval[1]) {
            compInterval[0] = min(intervals[i][0], compInterval[0]);
            compInterval[1] = max(intervals[i][1], compInterval[1]);
            ++i;
        }

        result.push_back(compInterval);
        while(i<n) result.push_back(intervals[i++]);
        return result;
    }
};
