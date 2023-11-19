# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/big-countries/).

# 2. Solution

## 2.1. MySQL

```sql
SELECT name, population, area FROM world WHERE (area >= 3000000 OR population >= 25000000)
```
