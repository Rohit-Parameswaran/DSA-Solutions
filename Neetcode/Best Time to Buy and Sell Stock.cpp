class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=1, max_profit = 0, n = prices.size();
        while(r<n) {
            max_profit = max(prices[r]-prices[l], max_profit);
            if(prices[r]<prices[l]) l=r;
            ++r;
        }
        return max_profit;
    }
};
