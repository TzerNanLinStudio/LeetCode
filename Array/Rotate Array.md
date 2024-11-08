# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/rotate-array/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**.

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)

        reverse(nums.begin(), nums.end()); // Reverse the entire array
        reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
        reverse(nums.begin() + k, nums.end()); // Reverse the rest of the elements after k
    }
};
```
