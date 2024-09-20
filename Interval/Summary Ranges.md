# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/summary-ranges/).

# 2. Solution

## 2.1. C++

The total time complexity of the solution is **O(n)**.

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> ranges;
        int rangeStart, rangeEnd;

        if (nums.empty()) {
            return ranges;
        }
            
        if (nums.size() == 1) {
            ranges.push_back(std::to_string(nums[0]));
            return ranges;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                rangeStart = nums[i];
                rangeEnd = nums[i];
            } else {
                if (nums[i] == rangeEnd + 1) {
                    // Extend the current range
                    rangeEnd = nums[i];
                } else {
                    // Add the current range to the result
                    if (rangeStart == rangeEnd) {
                        ranges.push_back(std::to_string(rangeStart));
                    } else {
                        ranges.push_back(std::to_string(rangeStart) + "->" + std::to_string(rangeEnd));
                    }
                    // Start a new range
                    rangeStart = nums[i];
                    rangeEnd = nums[i];
                }
            }
        }

        // Add the final range
        if (rangeStart == rangeEnd) {
            ranges.push_back(std::to_string(rangeStart));
        } else {
            ranges.push_back(std::to_string(rangeStart) + "->" + std::to_string(rangeEnd));
        }

        return ranges;
    }
};
```
