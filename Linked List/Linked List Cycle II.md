# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/linked-list-cycle-ii/).

# 2. Solution

## 2.1. C++

This is my initial idea, though it may not be the best approach.

```cpp
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *fast = head, *slow = head;
        do {
            if (fast->next == NULL || fast->next->next == NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;

        } while (fast != slow);

        ListNode *start = head, *meetingPoint = fast;
        while (start != meetingPoint) {
            start = start->next;
            meetingPoint = meetingPoint->next;
        }

        return start;
    }
};
```
