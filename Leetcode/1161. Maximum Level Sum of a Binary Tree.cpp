/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* breaker = new TreeNode();

        int level = 0, maxSum = INT_MIN, curLevel = 1, curSum = 0;
        q.push(root);
        q.push(breaker);

        while (!q.empty()) {
            if (q.front() == breaker) {
                q.pop();
                if (curSum > maxSum)
                    maxSum = curSum, level = curLevel;
                curLevel++;
                curSum = 0;
                if(!q.empty()) q.push(breaker);
            } else {
                curSum += (q.front())->val;
                if ((q.front())->left)
                    q.push((q.front())->left);
                if ((q.front())->right)
                    q.push((q.front())->right);
                q.pop();
            }
        }

        return level;
    }
};
