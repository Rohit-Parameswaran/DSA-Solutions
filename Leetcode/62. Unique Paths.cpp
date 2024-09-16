class Solution {
public:
    int uniquePaths(int &m, int &n) {
        vector<int> paths(n, 1);
         // current row will always have the value of the number of paths calculated in the previous iteration i.e, for the downward movement
        // in an iteration we therefore have to calculate only for the rightward movement and add it to downward movement paths (existing values)
        for(int i=m-2; i>=0 ; --i) {
            for(int j=n-2; j>=0 ; --j) {
                paths[j] += paths[j+1];
            }
        }
        return paths[0];
    }
};
