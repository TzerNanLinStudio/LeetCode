# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/jump-game/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**. The space complexity is **O(1)**.

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = nums[0];

        for (int i = 0; i < nums.size(); ++i) {
            if (maxIdx >= nums.size() - 1) return true; // 若 maxIdx 已達到或超過最後一個索引，則回傳 true
            if (nums[i] == 0 and maxIdx == i) return false; // 若遇到 0，且 maxIdx 無法超過該位置，則無法前進，回傳 false
            if (i + nums[i] > maxIdx) maxIdx = i + nums[i]; // 更新 maxIdx 為當前位置可跳到的最遠位置
        }

        return true;
    }
};
```
