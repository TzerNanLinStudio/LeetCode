# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/combine-two-tables/).

# 2. Solution

## 2.1. MySQL

```sql
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a ON p.personId = a.personId;
```
