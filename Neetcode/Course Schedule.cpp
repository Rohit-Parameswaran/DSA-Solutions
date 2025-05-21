class Solution {
public:
    bool dfs(int curnode, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &searched) {
        if(visited[curnode]) return false;
        visited[curnode] = true;
        for(auto it: adj[curnode]) {
            if(dfs(it, adj, visited, searched) == false) return false;
        }
        visited[curnode] = false;
        searched[curnode] = true;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> searched(numCourses, false);
        for(auto it: prerequisites)
            adj[it[0]].push_back(it[1]);
        
        for(int i=0; i<numCourses ; ++i) {
            if(searched[i] == false && dfs(i, adj, visited, searched) == false)
                return false;
        }
        return true;
    }
};
