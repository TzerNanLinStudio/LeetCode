# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/invalid-tweets/).

# 2. Solution

## 2.1. MySQL

```sql
SELECT tweet_id FROM Tweets WHERE CHAR_LENGTH(content) > 15;
```
