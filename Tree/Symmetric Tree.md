# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/add-two-numbers/).

# 2. Solution

## 2.1. Java

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
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
    if ((L == NULL && R != NULL) || (L != NULL && R == NULL))
        return false;
    if (L->val == R->val)
        return true && checkTree(L->right, R->left) && checkTree(L->left, R->right);
    else
        return false;    
}
```
