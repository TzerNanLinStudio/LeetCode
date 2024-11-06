# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/candy/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**.

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);  // Step 1: Initialize candies array with 1 candy for each child

        // Step 2: Left to right pass
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right to left pass
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum up all candies
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};
```
