/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        map<int, int> bv;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        pair<Node*, int> curEl;
        
        while(!q.empty()) {
        curEl = q.front();
        q.pop();
        auto curNode = curEl.first;
        auto breadth = curEl.second;
        bv[breadth] = curNode->data;
        if(curNode->left) q.push({curNode->left, breadth-1});
        if(curNode->right) q.push({curNode->right, breadth+1});
        }
        
        vector<int> result;
        for(auto it: bv) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
