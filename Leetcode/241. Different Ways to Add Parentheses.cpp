class Solution {
public:
    unordered_map<string, vector<int>> dp;

    int perform(int& x, int& y, char op) {
        switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        default:
            break;
        }
        return 0;
    }

    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> ans;

        string lexp, rexp;

        for (int i = 0; i < n; ++i) {
            if (!isdigit(expression[i])) {
                lexp = expression.substr(0, i);
                rexp = expression.substr(i + 1);

                if (!dp[lexp].size())
                    dp[lexp] = diffWaysToCompute(lexp);
                if (!dp[rexp].size())
                    dp[rexp] = diffWaysToCompute(rexp);

                for (auto l_it : dp[lexp]) {
                    for (auto r_it : dp[rexp]) {
                        ans.push_back(perform(l_it, r_it, expression[i]));
                    }
                }
            }
        }

        return expression.size() <= 2 ? (vector<int>({stoi(expression)})) : ans;
    }
};
