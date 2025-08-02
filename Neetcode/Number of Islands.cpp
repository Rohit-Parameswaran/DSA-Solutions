class Solution {
public:
    bool withinBounds(int i,int r) {
        return i>=0 && i<r;
    }
    void bfs(queue<pair<int, int>> &q, vector<vector<char>> &grid, int &m, int &n, vector<vector<bool>> &visited) {
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()) {
            auto cur = q.front();
            int i=cur.first, j=cur.second;
            q.pop();
            visited[i][j] = true;
            for(auto it: dir) {
                if(withinBounds(i+it[0], m) && withinBounds(j+it[1], n) && !visited[i+it[0]][j+it[1]] && grid[i+it[0]][j+it[1]] == '1') {
                    q.push({i+it[0], j+it[1]});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), islandCount=0;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        queue<pair<int, int>> q;
        for(int i=0 ; i<m ; ++i) {
            for(int j=0 ; j<n ; ++j) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    q.push({i,j});
                    bfs(q, grid, m, n, visited);
                    ++islandCount;
                }
            }
        }
        return islandCount;
    }
};
