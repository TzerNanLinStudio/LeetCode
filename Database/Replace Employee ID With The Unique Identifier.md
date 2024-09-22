# 1. Problem

The description of the problem is on LeetCode. Please refer to [Link](https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/).

# 2. Solution

## 2.1. MySQL

```sql
SELECT 
    EU.unique_id AS unique_id,
    E.name
FROM 
    Employees E
LEFT JOIN 
    EmployeeUNI EU
ON 
    E.id = EU.id;
```
