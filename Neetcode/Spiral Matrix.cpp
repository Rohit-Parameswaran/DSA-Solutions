class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), n = matrix.size();
        vector<int> res;
        vector<vector<int>> dir = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        int curdir = 0, curdim = m, i=0, j=-1;
        while(curdim > 0) {
            for(int x=0 ; x<curdim ; ++x){
                i += dir[curdir][0];
                j += dir[curdir][1];
                res.push_back(matrix[i][j]);
            }
            curdim = curdir & 1 ? --m : --n;
            curdir = (curdir+1)%4;
        }
        return res;
    }
};
