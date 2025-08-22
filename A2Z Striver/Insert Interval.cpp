class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0, n=intervals.size();
        vector<vector<int>> res;
        while(i<n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }
        auto temp = newInterval;
        while(i<n && intervals[i][0] <= newInterval[1]) {
            temp[0] = min(temp[0], intervals[i][0]);
            temp[1] = max(temp[1], intervals[i][1]);
            ++i;
        }
        res.push_back(temp);
        while(i<n) {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};
