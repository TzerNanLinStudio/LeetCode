# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/minimum-depth-of-binary-tree/).

# 2. Solution

## 2.1. C++

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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 1;
        
        if (root->left == nullptr)
            return minDepth(root->right) + 1;
        
        if (root->right == nullptr)
            return minDepth(root->left) + 1;

        return std::min(minDepth(root->left),  minDepth(root->right)) + 1;
    }
};
```

## 2.2. C#

```csharp
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
    public int MinDepth(TreeNode root) {
        if (root == null)
            return 0;
        
        if (root.left == null && root.right == null)
            return 1;
        
        if (root.left == null)
            return MinDepth(root.right) + 1;
        
        if (root.right == null)
            return MinDepth(root.left) + 1;

        return Math.Min(MinDepth(root.left), MinDepth(root.right)) + 1;
    }
}
```

## 2.3. Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        if root.left is None and root.right is None:
            return 1
        
        if root.left is None:
            return self.minDepth(root.right) + 1
        
        if root.right is None:
            return self.minDepth(root.left) + 1

        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1;
```
