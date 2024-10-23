# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link]https://leetcode.com/problems/count-complete-tree-nodes/).

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
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```
