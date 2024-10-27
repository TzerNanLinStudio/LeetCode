# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/minimum-absolute-difference-in-bst/).

# 2. Solution

## 2.1. Java

The time complexity is **O(n)**.

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
    // Initialize the minimum difference and the previous node's value
    private int minDifference = Integer.MAX_VALUE;
    private Integer previous = null;
    
    public int getMinimumDifference(TreeNode root) {
        DFS(root);
        return minDifference;
    }
    
    private void DFS(TreeNode root) {     
        if (root == null) return;

        // Inorder traversal of the left subtree
        DFS(root.left);
        
        // If the previous node is not null, calculate the difference between 
        // the current node and the previous node, and update the minimum difference
        if (previous != null) minDifference = Math.min(minDifference, root.val - previous);

        // Update the previous node value to the current node's value
        previous = root.val;
        
        // Inorder traversal of the right subtree
        DFS(root.right);
    }
}
```
