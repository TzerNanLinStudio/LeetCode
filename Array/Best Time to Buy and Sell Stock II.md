# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**. The space Complexity is **O(1)**.

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
```
