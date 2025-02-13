class Solution {
public:
    vector<vector<int>> buildAdjacency(int &n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

    void traverseComponent(vector<vector<int>> &adj, int i, vector<bool> &seen) {
        queue<pair<int, int>> q;
        q.push({i, -1});

        while(!q.empty()) {
            auto node = q.front().first, parent = q.front().second;
            for(auto it: adj[node]) {
                if(!seen[it] && it != parent) 
                    q.push({it, node});
            }
            seen[node] = true;
            q.pop();
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = buildAdjacency(n, edges);
        vector<bool> seen(n, false);
        int count = 0;

        for(int i=0 ; i<n ; ++i) {
            if(!seen[i]) {
                ++count;
                traverseComponent(adj, i, seen);
            }
        }

        return count;
    }
};
