/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> created;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        queue<Node*> q;
        q.push(node);
        created[node->val] = new Node(node->val);

        while(!q.empty()) {
            auto curnode = q.front();
            for(auto neighbor: curnode->neighbors) {
                if(!created[neighbor->val]) {
                    created[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                created[curnode->val]->neighbors.push_back(created[neighbor->val]);
            }
            q.pop();
        }
        return created[node->val];
    }
};
