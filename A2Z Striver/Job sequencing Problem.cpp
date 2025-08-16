class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int, int>> pd;
        int n=profit.size(), curProfit, curDeadline, totalProfit=0, noOfJobs=0;
        
        for(int i=0;i<n;++i) {
            pd.push_back({profit[i], deadline[i]});
        }
        
        int lastDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> doneTasks(lastDeadline+1, -1);
        
        sort(pd.begin(), pd.end(), greater<pair<int, int>>());
        for(int i=0 ; i<n ;++i) {
            curProfit = pd[i].first;
            curDeadline = pd[i].second;

            while(curDeadline>0 && doneTasks[curDeadline] != -1) {
                --curDeadline;
            }
            if(curDeadline > 0) {
                doneTasks[curDeadline] = curProfit;
                noOfJobs++ ;
                totalProfit += curProfit ;
            }
        }

        return {noOfJobs, totalProfit};
    }
};
