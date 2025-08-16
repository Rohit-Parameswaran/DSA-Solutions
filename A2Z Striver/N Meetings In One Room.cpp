class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size(), maxMeetings = 0, curEnd = -1;
        vector<pair<int, int>> intervals;
        for(int i=0 ; i<n ; ++i) {
            intervals.push_back({start[i], end[i]});
        }
        sort(intervals.begin(), intervals.end());
        for(int i=0 ; i<n ; ++i) {
            if(intervals[i].first > curEnd) {
                ++maxMeetings;
                curEnd = intervals[i].second;
            }
            else {
                curEnd = min(curEnd, intervals[i].second);
            }
        }
        return maxMeetings;
    }
};
