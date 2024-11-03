# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**.

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int duplicateCount = 0; // Track the number of extra duplicates to be removed
        for (int currentIdx = 2; currentIdx < nums.size() - duplicateCount; currentIdx++) {
            nums[currentIdx] = nums[currentIdx + duplicateCount];

            // Check if current element has more than two duplicates
            if (nums[currentIdx] == nums[currentIdx - 1] && nums[currentIdx] == nums[currentIdx - 2]) {
                duplicateCount++; // Increment duplicate counter
                currentIdx--; // Step back to recheck the next element at this position
            }
        }

        return nums.size() - duplicateCount;
    }
};
```
