class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev_row;
        vector<int> cur_row(n+1, 1);
        for(int j=1;j<m;++j) {
            prev_row = cur_row;
            prev_row[0] = 0;
            cur_row = vector<int> (n+1, 0);
            for(int i=1;i<=n;++i) {
                cur_row[i] = prev_row[i] + cur_row[i-1];
            }
        }
        return cur_row[n];
    }
};
