/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
    string nullStr = "N.";
public:
    string popNextNum(string s, int &i) {
        int n = s.size();
        string ans;
        while(i<n && s[i] != '.') {
            ans.push_back(s[i++]);
        }
        ++i;
        return ans;
    }
    TreeNode* createNodeWithNum(string s) {
        if(s == "N") return NULL;
        return new TreeNode(stoi(s));
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return nullStr;
        string s;
        queue<TreeNode*> q;
        q.push(root);
        s += to_string(root->val) + ".";
        while(!q.empty()) {
            auto curNode = q.front();
            q.pop();
            if(curNode->left) {
                q.push(curNode->left);
                s += to_string((curNode->left)->val) + ".";
            } else {
                s += nullStr;
            } 
            if(curNode->right) {
                q.push(curNode->right);
                s += to_string((curNode->right)->val) + ".";
            } else {
                s += nullStr;
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int curPos = 0;
        string num = popNextNum(data, curPos);
        TreeNode *root = createNodeWithNum(num);
        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()) {
            auto curNode = q.front();
            q.pop();
            string l = popNextNum(data, curPos);
            curNode->left = createNodeWithNum(l);
            string r = popNextNum(data, curPos);
            curNode->right = createNodeWithNum(r);
            if(curNode->left) q.push(curNode->left);
            if(curNode->right) q.push(curNode->right);
        }
        return root;
    }
};
