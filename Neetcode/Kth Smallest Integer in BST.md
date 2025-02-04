Your solution is an implementation of **Morris Traversal** to find the **k-th smallest element** in a Binary Search Tree (BST). Since you're using Morris Traversal, it achieves **O(1) extra space complexity** while still following an **in-order traversal** (left-root-right), which naturally processes elements in sorted order for a BST.

**Step-by-Step Breakdown**
Let's go over the approach and why this works.

**1. Understanding the Problem**
* Given a BST, we want to find the **k-th smallest element**.
* Since in-order traversal of a BST visits elements in sorted order, the **k-th** element we visit is the answer.
* Morris Traversal helps achieve this **without recursion or an explicit stack**.

**2. Morris Traversal: How It Works**
Morris Traversal modifies the BST structure temporarily to avoid using a stack or recursion.
1. **If** `curr` has no left child
  * Process the node (decrement `k`).
  * Move to `curr->right`.
2. **If** `curr` has a left child
  * Find its **predecessor** (rightmost node in `curr->left` subtree).
  * If `pred->right` is `nullptr`, establish a **temporary link** to `curr` (threading).
  * If `pred->right == curr`, remove the temporary link and process `curr`.
This ensures we **visit every node exactly once** and still follow in-order traversal.

**3. Dry Run with an Example**
Let's take a BST:

```
      5
     / \
    3   6
   / \
  2   4
 /
1
```

and find `k = 3` (which should return `3`).

**Step-by-Step Execution**
1. `curr = 5`
  * It has a left subtree (`3`), find predecessor (`4`).
  * `4->right == nullptr`, so we set `4->right = 5` (threading).
  * Move `curr = 3`.
2. `curr = 3`
  * It has a left subtree (`2`), find predecessor (`2`).
  * `2->right == nullptr`, set `2->right = 3`.
  * Move `curr = 2`.
3. `curr = 2`
  * It has a left subtree (`1`), find predecessor (`1`).
  * `1->right == nullptr`, set `1->right = 2`.
  * Move `curr = 1`.
4. `curr = 1`
  * No left subtree, process it (`k--`, `k=2`).
  * Move `curr = 2`.
5. `curr = 2`
  * `1->right` was `curr`, revert (`1->right = nullptr`).
  * Process `2` (`k--`, `k=1`).
  * Move `curr = 3`.
6. `curr = 3`
  * `2->right` was `curr`, revert (`2->right = nullptr`).
  * Process `3` (`k--`, `k=0`). **Found answer!**
✅ **Return 3**.

**4. Time & Space Complexity**
* **Time Complexity**:
  * Each node is visited at most **twice** (once to set up threading, once to revert).
  * This results in **O(n)** time.
* **Space Complexity**:
  * Since we **don't use recursion or an explicit stack**, we only modify pointers.
  * This results in **O(1) extra space**.

**5. Why Morris Traversal Instead of Recursion or Stack?**

| Approach | Time Complexity | Space Complexity | Explanation |
|----------|----------------|------------------|-------------|
| Recursive In-Order | O(n) | O(h) (stack) | Uses recursive calls (O(h) space for call stack). |
| Iterative In-Order | O(n) | O(h) | Uses explicit stack (O(h) space). |
| Morris Traversal | O(n) | O(1) | No extra space, modifies tree temporarily. |

If memory is **not a concern**, iterative or recursive in-order traversal is **simpler**. But **Morris Traversal** is useful when **space is constrained**.

**6. Key Takeaways**
* **Morris Traversal** is an in-order traversal technique that avoids recursion and stack.
* It **modifies the BST temporarily** using threading.
* It processes elements in **sorted order**, so decrementing `k` ensures we get the `k-th` smallest element.
* The BST structure is **restored** after processing.

Would you like to compare this with other approaches in code? 🚀
