class Solution {
    vector<int> rdirs = {-1, 0, 1, 0};
    vector<int> cdirs = {0, 1, 0, -1};
public:
    bool isInBounds(int i, int j, int m, int n) {
        return i>=0 && i<m && j>=0 && j<n;
    }

    void findAllReachable(queue<vector<int>> &q, const vector<vector<int>> &heights, vector<vector<bool>> &visited) {
        int m=heights.size(), n=heights[0].size(), i, j, new_i, new_j;

        while(!q.empty()) {
            auto el = q.front();
            i=el[0], j=el[1];
            q.pop();
            for(int x=0 ; x<4 ; ++x) {
                new_i=i+rdirs[x], new_j=j+cdirs[x];                
                if(isInBounds(new_i, new_j, m, n) && heights[new_i][new_j] >= heights[i][j] && !visited[new_i][new_j]){
                    q.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size(), i, j;
        
        vector<vector<bool>> pacific_reachable(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic_reachable(m, vector<bool>(n, false));

        queue<vector<int>> q;
        for(i=0 ; i<m ; ++i) {
            q.push({i,0});
            pacific_reachable[i][0] = true;
        }
        for(j=1 ; j<n ; ++j) {
            q.push({0,j});
            pacific_reachable[0][j] = true;
        }
        findAllReachable(q, heights, pacific_reachable);

        
        for(i=0 ; i<m-1 ; ++i) {
            q.push({i,n-1});
            atlantic_reachable[i][n-1] = true;
        }
        for(j=0 ; j<n ; ++j) {
            q.push({m-1,j});
            atlantic_reachable[m-1][j] = true;
        }
        findAllReachable(q, heights, atlantic_reachable);

        vector<vector<int>> res;
        for(i=0 ; i<m ; ++i) {
            for(j=0 ; j<n ; ++j) {
                if(atlantic_reachable[i][j] && pacific_reachable[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
