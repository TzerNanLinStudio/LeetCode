# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/find-customer-referee/).

# 2. Solution

## 2.1. MySQL

### 2.1.1. Approach One

```sql
SELECT name FROM Customer WHERE COALESCE(referee_id,0) <> 2;
```

### 2.1.2. Approach Two

```sql
SELECT name FROM Customer WHERE referee_id IS NULL OR referee_id <> 2;
```
