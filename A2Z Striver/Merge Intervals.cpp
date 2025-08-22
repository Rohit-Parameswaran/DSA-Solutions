class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        vector<vector<int>> res;
        vector<int> curInterval = intervals[0];
        for(int i=0 ; i<n ; ++i) {
            if(curInterval[1] < intervals[i][0]) {
                res.push_back(curInterval);
                curInterval = intervals[i];
            } else {
                curInterval[0] = min(curInterval[0], intervals[i][0]);
                curInterval[1] = max(curInterval[1], intervals[i][1]);
            }
        }
        res.push_back(curInterval);
        return res;
    }
};
