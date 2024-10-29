# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/reverse-words-in-a-string/).

# 2. Solution

## 2.1. C++

The time complexity is **O(n)**.

```cpp
class Solution {
public:
    std::string reverseWords(const std::string& s) {
        std::istringstream stream(s);  // Initialize a string stream with the input string
        std::string answer, word;
        bool firstWord = true;

        // Use stringstream to read each word and insert it in reverse order
        while (stream >> word) {
            // Add the new word at the beginning of the existing string
            if (firstWord) {
                answer = word;        // Initialize 'answer' with the first word
                firstWord = false;
            } else {
                answer = word + " " + answer;  // Prepend each new word with a space
            }
        }

        std::cout << answer << std::endl;  // Output the reversed words
        return answer;
    }
};
```
