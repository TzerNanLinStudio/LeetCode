# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/reverse-nodes-in-k-group/).

# 2. Solution

## 2.1. C

```c

```

## 2.2. C++

### 2.2.1. Approach One

This approach is designed by myself.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* former_pointer = nullptr;
        ListNode* latter_pointer = head;
        int number = 0;

        if (k == 1 || head->next == nullptr)
            return head;

        while (latter_pointer != nullptr)
            if (++number == k) {
                ListNode* original_head = former_pointer == nullptr ? head : former_pointer->next;
                ListNode* original_tail = latter_pointer;
                latter_pointer = latter_pointer->next;
                number = 0;

                reverseLinkedList(original_head, original_tail); // (original_head, original_tail) -> (original_tail, original_head)

                if (former_pointer == nullptr) 
                    head = original_tail;
                else 
                    former_pointer->next = original_tail;
                former_pointer = original_head;
                original_head->next = latter_pointer;
            }
            else 
                latter_pointer = latter_pointer->next;
        
        return head;
    }

    void reverseLinkedList(ListNode* head, ListNode* tail) {
        ListNode* last = nullptr;
   
        while (last != tail) {
            ListNode* next = head->next;
            head->next = last;

            last = head;
            head = next;
        }
    }
};
```

### 2.2.2. Approach Two

This approach is provided by other people.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* former_pointer = nullptr;
        ListNode* latter_pointer = head;
        int number = 0;

        if (k == 1 || head->next == nullptr)
            return head;

        while (latter_pointer != nullptr)
            if (++number == k) {
                ListNode* original_head = former_pointer == nullptr ? head : former_pointer->next;
                ListNode* original_tail = latter_pointer;
                latter_pointer = latter_pointer->next;
                number = 0;

                reverseLinkedList(original_head, original_tail); // (original_head, original_tail) -> (original_tail, original_head)

                if (former_pointer == nullptr) 
                    head = original_tail;
                else 
                    former_pointer->next = original_tail;
                former_pointer = original_head;
                original_head->next = latter_pointer;
            }
            else 
                latter_pointer = latter_pointer->next;
        
        return head;
    }

    void reverseLinkedList(ListNode* head, ListNode* tail) {
        ListNode* last = nullptr;
   
        while (last != tail) {
            ListNode* next = head->next;
            head->next = last;

            last = head;
            head = next;
        }
    }
};
```

