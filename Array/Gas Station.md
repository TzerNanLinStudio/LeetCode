# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/gas-station/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**. The space Complexity is **O(1)**.

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;   // 用於追蹤總汽油盈餘
        int current_tank = 0; // 用於追蹤局部汽油盈餘
        int start_index = 0;  // 起始加油站的索引

        for (int i = 0; i < gas.size(); ++i) {
            int fuel_difference = gas[i] - cost[i];
            total_tank += fuel_difference;
            current_tank += fuel_difference;

            // 如果局部汽油盈餘小於0，無法從當前起點到達下一站
            if (current_tank < 0) {
                start_index = i + 1;  // 更新起點為下一站
                current_tank = 0;     // 重置局部汽油盈餘
            }
        }

        // 如果總汽油盈餘小於0，無法完成環繞，返回-1
        return total_tank >= 0 ? start_index : -1;
    }
};
```
