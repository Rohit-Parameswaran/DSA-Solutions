// My initial solution
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=arr.size(), maxPlatforms=0;
        vector<pair<int, int>> intervals;
        for(int i=0 ; i<n ; ++i) {
            intervals.push_back({arr[i], dep[i]});
        }
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0 ; i<n ; ++i) {
            if(!minHeap.empty() && (intervals[i].first <= minHeap.top())) {
                minHeap.push(intervals[i].second);
            }
            else {
                while(!minHeap.empty() && intervals[i].first > minHeap.top()) {
                    minHeap.pop();
                }
                minHeap.push(intervals[i].second);
            }
            maxPlatforms = max(maxPlatforms, (int)minHeap.size());
        }
        return maxPlatforms;
    }
};


// Better solution that simulates the arrival and departure of trains in a railway station. Sort arr and dep separately
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i=0, j=0, n=arr.size(), curPlatforms = 0, maxPlatforms = 1;
        while(i<n) {
            if(arr[i] <= dep[j]) {
                ++curPlatforms;
                ++i;
            }
            else {
                --curPlatforms;
                ++j;
            }
            maxPlatforms = max(maxPlatforms, curPlatforms);
        }
        return maxPlatforms;
    }
};
