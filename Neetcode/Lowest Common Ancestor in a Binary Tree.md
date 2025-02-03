# Lowest Common Ancestor (LCA) of a Binary Tree

The Lowest Common Ancestor (LCA) of two nodes p and q in a binary tree is the lowest node in the tree that has both p and q as descendants.

## Optimized Recursive Approach (O(n) Time, O(h) Space)

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root; // p and q are found in different subtrees
        return left ? left : right;     // Return non-null subtree
    }
};
```

### Explanation

**Base Case:**
- If root is nullptr, return nullptr.
- If root matches p or q, return root.

**Recursive Calls:**
- Recursively search in the left and right subtrees.
  - `left = lowestCommonAncestor(root->left, p, q)`
  - `right = lowestCommonAncestor(root->right, p, q)`

**Conditions to Determine LCA:**
- If both left and right are non-null, root is the LCA (p is in one subtree, q in another).
- If only one subtree returns a non-null value, return that.

### Complexity Analysis
- ✅ Time Complexity: O(n) (Each node is visited once)
- ✅ Space Complexity: O(h) (Recursive depth, where h = height of tree)

### Edge Cases
- ✔️ p or q is root → The root itself is LCA
- ✔️ p or q is not in the tree → Returns the node found or nullptr
- ✔️ p and q are the same node → Returns p or q
- ✔️ Tree has only one node → That node is the LCA

### Alternative: Iterative Approach (Using Parent Mapping & Set)
- 🔹 Use a HashMap to store each node's parent and traverse upwards from p and q
- 🔹 Not as clean as the recursive approach but works well in some cases
