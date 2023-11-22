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
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(0)
        tail = dummyHead
        carry = 0

        while l1 is not None or l2 is not None or carry != 0:
            digit1 = l1.val if l1 is not None else 0
            digit2 = l2.val if l2 is not None else 0

            sum = digit1 + digit2 + carry
            digit = sum % 10
            carry = sum // 10

            newNode = ListNode(digit)
            tail.next = newNode
            tail = tail.next

            l1 = l1.next if l1 is not None else None
            l2 = l2.next if l2 is not None else None

        result = dummyHead.next
        dummyHead.next = None
        return result
```
