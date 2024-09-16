class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int f=cost[0], s=cost[1], t;
        for(int i=2; i<n ; ++i) {
            t = cost[i] + min(f, s);
            f=s, s=t;
        }
        return min(f, s);
    }
};
