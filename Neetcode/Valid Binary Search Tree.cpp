class Solution {
public:
    bool isValidBSTHelper(TreeNode* root, int ll, int rl) {
        if(!root) return true;

        if(ll < root->val && root->val < rl)
            return isValidBSTHelper(root->left, ll, root->val) && isValidBSTHelper(root->right, root->val, rl);
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT_MIN, INT_MAX);
    }
};
