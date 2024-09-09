# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/isomorphic-strings/).

# 2. Solution

## 2.1. C++

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(128, 0); // Stores index of characters in string s
        vector<int> indexT(128, 0); // Stores index of characters in string t

        if (s.length() != t.length()) return false; // If the lengths of the two strings are different, they can't be isomorphic

        for (int i = 0; i < s.length(); i++) { // Iterate through each character of the strings
            if (indexS[s[i]] != indexT[t[i]]) return false; // If the index of the current character in string s is different from the index of the corresponding character in string t, they can't be isomorphic

            indexS[s[i]] = i + 1; // updating position of current character
            indexT[t[i]] = i + 1; // updating position of current character
        }

        return true; // If the loop completes without returning false, strings are isomorphic
    }
};
```
