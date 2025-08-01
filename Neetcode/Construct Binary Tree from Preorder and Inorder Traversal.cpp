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

class Solution {
    int ppos = -1;
public:
    TreeNode* buildTreeUtil(vector<int>& po, int l, int r, unordered_map<int, int> &inorderPos) {
        if(l>r) return nullptr;
        ++ppos;
        if(ppos >= po.size()) return nullptr;
        int curVal = po[ppos];
        TreeNode *root = new TreeNode(curVal);
        root->left = buildTreeUtil(po, l,inorderPos[curVal]-1, inorderPos);
        root->right = buildTreeUtil(po, inorderPos[curVal]+1, r, inorderPos);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inorderPos;
        for(int i=0 ; i<n ; ++i)
            inorderPos[inorder[i]] = i;
        return buildTreeUtil(preorder, 0, n-1, inorderPos);
    }
};
