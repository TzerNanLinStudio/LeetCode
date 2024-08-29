# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/ransom-note/).

# 2. Solution

## 2.1. C++

### 2.2.1. Approach One

This is my initial idea, though it may not be the best approach.

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int matchCount = 0; // Counter to track the number of matched characters

        for (int i = 0; i < ransomNote.size(); i++) {
            char currentChar = ransomNote[i]; // The current character to find in the magazine
            size_t foundPos = magazine.find(currentChar); // Find the position of the current character in the magazine

            if (foundPos == std::string::npos) break; // If the character is not found, exit the loop

            magazine.erase(foundPos, 1); // Remove the found character from the magazine
            matchCount++; // Increment the match counter
        }

        return matchCount == ransomNote.size(); // Return true if all characters are matched successfully
    }
};
```

### 2.2.1. Approach Two

This is ChatGPT's idea, though it may be a better approach.

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Create an array to count frequencies of each letter in the magazine
        vector<int> letterCount(26, 0);

        // Count each letter in the magazine
        for (char c : magazine) {
            letterCount[c - 'a']++;
        }

        // Check if ransomNote can be constructed
        for (char c : ransomNote) {
            if (letterCount[c - 'a'] == 0) {
                return false;
            }
            letterCount[c - 'a']--;
        }

        return true;
    }
};
```
