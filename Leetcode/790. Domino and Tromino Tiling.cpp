#define MOD 1000000007
class Solution {
public:
    int numTilings(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        vector<long long int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        long long int sumTillIMinus3 = 0;
        for(int i=3 ; i<=n ; ++i) {
            sumTillIMinus3 = (sumTillIMinus3 + dp[i-3]) % MOD;
            dp[i] = (dp[i-1] + dp[i-2] + 2*sumTillIMinus3) % MOD;
        }

        return dp[n];        
    }
};
