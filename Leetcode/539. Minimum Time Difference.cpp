class Solution {
public:
    int getNum(int i, int j) { return 10 * (i - '0') + (j - '0'); }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> tim;
        for (auto it : timePoints) {
            tim.push_back(getNum(it[0], it[1]) * 60 + getNum(it[3], it[4]));
        }

        sort(tim.begin(), tim.end());
        tim.push_back(tim[0] + 24 * 60);
        int min_dif = INT_MAX;
        for (int i = 1; i < tim.size(); ++i) {
            min_dif = min(min_dif, tim[i] - tim[i - 1]);
        }

        return min(min_dif, tim[tim.size() - 1] - tim[0]);
    }
};
