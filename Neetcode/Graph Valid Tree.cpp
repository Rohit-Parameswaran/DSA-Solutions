typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef unordered_set<int> uosi;
class Solution {
public:
    bool isTree(int node, vvi &adj, uosi &seen, int parent) {
        seen.insert(node);
        for(auto edge_to: adj[node]) {
            if(edge_to != parent) {
                if(seen.count(edge_to) || !isTree(edge_to, adj, seen, node))
                    return false;
            };
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(n == 1 && edges.size() == 0) return true;     
        vvi adj(n);
        for(auto edge: edges) {
            if(edge[0] == edge[1]) return false;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(auto it: adj) if(it.size() == 0) return false;

        vi curp(n, 0);
        uosi seen;
        if(!isTree(0, adj, seen, -1)) {
            return false;
        };
        return seen.size() == n;
    }
};
