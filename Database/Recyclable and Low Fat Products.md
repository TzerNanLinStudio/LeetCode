# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/recyclable-and-low-fat-products/).

# 2. Solution

## 2.1. MySQL

```sql
select product_id from Products where low_fats = 'Y' and recyclable = 'Y'
```
