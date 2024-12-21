# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/integer-to-roman/).

# 2. Solution

## 2.1. C++

The time complexity is **O(1)**. The space Complexity is **O(1)**.

```cpp
class Solution {
public:
    string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        int index = 0;
        std::string answer = "";

        while (num > 0 && index < roman.size()) {
            if (num >= roman[index].first) {
                answer += roman[index].second;
                num -= roman[index].first;
            }
            else {
                index++;
            }
        }

        return answer;
    }
};
```
