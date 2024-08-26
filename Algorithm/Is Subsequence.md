# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/is-subsequence/).

# 2. Solution

## 2.1. C++

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;

        int sPointer = 0;
        int tPointer = 0;
        while (sPointer < s.size() && tPointer < t.size()) {
            if (s[sPointer] == t[tPointer]) sPointer++;
            tPointer++;     
        }

        return sPointer == s.size();
    }
};
```
