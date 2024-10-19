# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link]https://leetcode.com/problems/same-tree/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**.

```cpp
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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base cases: both are null or one is null
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Check the current node's value
        if (p->val != q->val) {
            return false;
        }

        // Recursively check the left and right subtrees
        bool leftSame = isSameTree(p->left, q->left);
        bool rightSame = isSameTree(p->right, q->right);

        // Both subtrees need to be identical
        return leftSame && rightSame;
    }
};
```
