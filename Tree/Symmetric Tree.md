# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/add-two-numbers/).

# 2. Solution

## 2.1. Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public boolean isSymmetric(TreeNode root) {
	    return isSymmetric(root.left, root.right);
    }

    public boolean isSymmetric(TreeNode rootleft, TreeNode rootright) {
        if (rootleft == null && rootright == null)
            return true;
        else if (rootleft == null || rootright == null)
            return false;
        else if (rootleft.val != rootright.val)
            return false;
        else if (!isSymmetric(rootleft.left, rootright.right))
            return false;
        else if (!isSymmetric(rootleft.right, rootright.left))
            return false;
        else
            return true;
    }
}
```

## 2.2. C

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkTree(struct TreeNode* L, struct TreeNode* R);

bool isSymmetric(struct TreeNode* root){
    return checkTree(root->left, root->right);
}

bool checkTree(struct TreeNode* L, struct TreeNode* R){
    if (L == NULL && R == NULL)
        return true;
    if (L == NULL || R == NULL)
        return false;
    if (L->val == R->val)
        return true && checkTree(L->right, R->left) && checkTree(L->left, R->right);
    else
        return false;    
}
```
