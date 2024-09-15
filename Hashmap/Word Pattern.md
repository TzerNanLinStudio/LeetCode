# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/word-pattern/).

# 2. Solution

## 2.1. C++

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Use istringstream to split the string 's' into individual words
        std::istringstream stream(s);
        std::string currentWord;
        std::vector<std::string> words;

        // Extract words from the string and store them in the 'words' vector
        while (stream >> currentWord) {
            words.push_back(currentWord);
        }

        // If the number of words doesn't match the pattern length, return false
        if (words.size() != pattern.size()) {
            return false;
        }

        // Maps to track character-to-word and word-to-character relationships
        std::map<char, std::string> patternToWordMap;
        std::map<std::string, char> wordToPatternMap;

        // Iterate through the pattern and words
        for (int i = 0; i < pattern.size(); i++) {
            char currentPatternChar = pattern[i];
            const std::string& word = words[i];

            // If the character and word aren't mapped yet, map them
            if (patternToWordMap[currentPatternChar].empty() && wordToPatternMap[word] == '\0') {
                patternToWordMap[currentPatternChar] = word;
                wordToPatternMap[word] = currentPatternChar;
            }
            // If there's a mismatch in the current mappings, return false
            else if (patternToWordMap[currentPatternChar] != word || wordToPatternMap[word] != currentPatternChar) {
                return false;
            }
        }

        // Return true if all character-word mappings are consistent
        return true;
    }
};
