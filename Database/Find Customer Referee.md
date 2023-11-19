# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/find-customer-referee/).

# 2. Solution

## 2.1. MySQL

```sql
SELECT name FROM Customer WHERE COALESCE(referee_id,0) <> 2;
```
