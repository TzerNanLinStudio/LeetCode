# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/h-index/).

# 2. Solution

## 2.1. C++

The time complexity is **O(nlogn)** because of QuickSort or HeapSort. The space complexity is **O(logn)** because of QuickSort or HeapSort.

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for (int i = 0, n = citations.size(); i < n; i++)
            if (n - i <= citations[i])
                return n - i;
        return 0;
    }
};
```
