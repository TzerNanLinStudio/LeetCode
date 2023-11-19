# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/recyclable-and-low-fat-products/).

# 2. Solution

## 2.1. MySQL

```sql
SELECT product_id FROM Products WHERE low_fats = 'Y' AND recyclable = 'Y'
```
