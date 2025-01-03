# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/zigzag-conversion/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**. The space complexity is **O(n)**.

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        // 如果行數為 1 或字串太短，直接返回
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        // 用於存儲每一行的結果
        vector<string> rows(min(numRows, (int)s.length()));
        int currentRow = 0; // 當前行數
        bool goingDown = false; // 行進方向

        // 遍歷字串並按 Z 字形填充到每一行
        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown; // 到頂或到底時反轉方向
            }
            currentRow += goingDown ? 1 : -1; // 更新行數
        }
        
        // 拼接所有行的結果
        string result;
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};
```
