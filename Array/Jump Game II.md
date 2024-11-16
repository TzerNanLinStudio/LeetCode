# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/jump-game-ii/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**. The space complexity is **O(1)**.

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        // 第一個 for 迴圈：預處理 nums 陣列，更新每個位置的值為最遠可跳到的索引
        for (int i = 1; i < nums.size(); i++) {
            // 更新 nums[i] 為 max(從當前位置 i 能跳到的最遠位置, 前一個位置能跳到的最遠位置)
            nums[i] = max(nums[i] + i, nums[i - 1]);
        }

        int ind = 0;  // 當前索引，從起點開始
        int ans = 0;  // 跳躍次數

        // 第二個 while 迴圈：計算從起點到終點所需的最少跳躍次數
        while (ind < nums.size() - 1) {
            ans++;               // 每次跳躍次數 +1
            ind = nums[ind];     // 更新 ind 為當前位置能跳到的最遠索引
        }

        return ans; // 返回最少的跳躍次數
    }
};
```
