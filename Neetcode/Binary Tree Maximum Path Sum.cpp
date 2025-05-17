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

struct PathInfo {
    int lsi;
    int rsi;

    PathInfo() {}

    PathInfo(int a, int b) {
        lsi = a;
        rsi = b;
    }
};

class Solution {
    int maxSum;
public:
    Solution():maxSum(INT_MIN) {}
    PathInfo dfs(TreeNode* root) {
        if(!root) {
            return *(new PathInfo(0,0));
        }

        auto linfo = dfs(root->left);
        auto rinfo = dfs(root->right);
        PathInfo cinfo;
        cinfo.lsi = max(linfo.lsi, linfo.rsi);
        cinfo.lsi = max(root->val, cinfo.lsi+root->val);
        cinfo.rsi = max(rinfo.lsi, rinfo.rsi);
        cinfo.rsi = max(root->val, cinfo.rsi+root->val);


        int greatest_sum_incl_cur_node = max(max(cinfo.lsi, cinfo.rsi), cinfo.lsi+cinfo.rsi-root->val);
        maxSum = max(maxSum, greatest_sum_incl_cur_node);
        return cinfo;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
