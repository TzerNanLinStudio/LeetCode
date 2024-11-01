
# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/average-of-levels-in-binary-tree/).

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            double levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }

            result.push_back(levelSum / levelSize);
        }

        return result;
    }
};
```
